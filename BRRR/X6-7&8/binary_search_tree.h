#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include <stdexcept>
#include <algorithm>
#include <iostream>
using namespace std;

template<typename Comparable>
class BinarySearchTree {
private:
	struct BinaryNode {
		Comparable element;
		BinaryNode* left;
		BinaryNode* right;
		BinaryNode* parent;

		BinaryNode(const Comparable& theElement, BinaryNode* lt, BinaryNode* rt, BinaryNode* p) :
			element{ theElement }, left{ lt }, right{ rt }, parent(p) { }
	};

	BinaryNode* root;

	/**
	 * Internal method to insert into a subtree.
	 * x is the item to insert.
	 * t is the node that roots the subtree.
	 * Set the new root of the subtree.
	 */
	BinaryNode* insert(const Comparable& x, BinaryNode*& t, BinaryNode* parent) {
		if (t == nullptr) {
			t = new BinaryNode{ x, nullptr, nullptr, parent };
			return t;
		}
		else {
			if (x < t->element)
				return insert(x, t->left, t);
			else if (t->element < x)
				return insert(x, t->right, t);
			else {
				return t;
			}
		}
	}

	/**
	 * Internal method to remove from a subtree.
	 * x is the item to remove.
	 * t is the node that roots the subtree.
	 * Set the new root of the subtree.
	 */
	void remove(const Comparable& x, BinaryNode*& t) {
		if (t == nullptr)
			return;				// Item not found; do nothing
		if (x < t->element)
			remove(x, t->left);
		else if (t->element < x)
			remove(x, t->right);
		else if (t->left != nullptr && t->right != nullptr)	// Two children
		{
			t->element = findMin(t->right)->element;
			remove(t->element, t->right);
		}
		else {
			BinaryNode* oldNode = t;
			BinaryNode* p = t->parent;
			if (t->left != nullptr) {
				t = t->left;
			}
			else {
				t = t->right;
			}
			if (t != nullptr)
				t->parent = p;
			delete oldNode;
		}
	}

	/**
	 * Internal method to find the smallest item in a subtree t.
	 * Return node containing the smallest item.
	 */
	BinaryNode* findMin(BinaryNode* t) const {
		if (t == nullptr)
			return nullptr;
		if (t->left == nullptr)
			return t;
		return findMin(t->left);
	}

	/**
	 * Internal method to find the largest item in a subtree t.
	 * Return node containing the largest item.
	 */
	BinaryNode* findMax(BinaryNode* t) const {
		if (t != nullptr)
			while (t->right != nullptr)
				t = t->right;
		return t;
	}

	/**
	 * Internal method to test if an item is in a subtree.
	 * x is item to search for.
	 * t is the node that roots the subtree.
	 */
	BinaryNode* contains(const Comparable& x, BinaryNode* t) const {
		if (t == nullptr)
			return nullptr;
		else if (x < t->element)
			return contains(x, t->left);
		else if (t->element < x)
			return contains(x, t->right);
		else
			return t;	// Match
	}

	/**
	 * Internal method to make subtree empty.
	 */
	void makeEmpty(BinaryNode*& t) {
		if (t != nullptr) {
			makeEmpty(t->left);
			makeEmpty(t->right);
			delete t;
		}
		t = nullptr;
	}

	/**
	 * Internal method to print a subtree rooted at t in sorted order.
	 */
	void printTree(BinaryNode* t, ostream& out) const {
		if (t != nullptr) {
			printTree(t->left, out);
			std::cout << t->element << std::endl;
			printTree(t->right, out);
		}
	}

	/**
	 * Internal method to clone subtree.
	 */
	BinaryNode* clone(BinaryNode* t) const {
		if (t == nullptr)
			return nullptr;
		else
			return new BinaryNode{ t->element, clone(t->left), clone(t->right), t };
	}

public:
	BinarySearchTree() : root{ nullptr } {}

	BinarySearchTree(const BinarySearchTree& rhs) : root{ nullptr } {
		root = clone(rhs.root);
	}

	~BinarySearchTree() { makeEmpty(); }

	BinarySearchTree& operator=(const BinarySearchTree& rhs) {
		BinarySearchTree copy(rhs);
		std::swap(*this, copy);
		return *this;
	}

	class iterator {
	private:
		BinaryNode* node;

	public:
		friend class BinarySearchTree<Comparable>;

		iterator() : node(nullptr) {}

		iterator(BinaryNode* newNode) : node(newNode) {}

		bool operator ==(iterator it) const {
			return node == it.node;
		}

		bool operator !=(iterator it) const {
			return node != it.node;
		}

		iterator& operator ++() {
			if (node == nullptr) {
				return *this; // Safeguard against null node
			}
			if (node->right != nullptr) {
				node = node->right;
				while (node->left != nullptr) {
					node = node->left;
				}
			}
			else {
				BinaryNode* parent = node->parent;
				while (parent != nullptr && node == parent->right) {
					node = parent;
					parent = parent->parent;
				}
				node = parent;
			}
			return *this;
		}

		iterator operator ++(int) {
			iterator it(*this);
			++(*this);
			return it;
		}

		Comparable& operator*() {
			return node->element;
		}

		Comparable* operator->() {
			return&node->element;
		}

		iterator& operator=(iterator it) {
			node = it.node;
			return *this;
		}
	};

	const iterator findMin() const;
	const iterator findMax() const;
	bool isEmpty() const; // test for emptiness
	void printTree(ostream& out = cout) const;
	void makeEmpty(); // empty tree
	bool contains(const Comparable& x) const; // look for item
	void remove(const Comparable& x); // remove item
	iterator insert(const Comparable& x); // insert item
	iterator find(const Comparable& x); // insert item
	iterator erase(iterator& itr);
};

#include "binary_search_tree.tpp"

#endif
