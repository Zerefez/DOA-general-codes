#include <vector>
#include "binary_search_tree.h"

using namespace std;

template<typename Comparable>
class OrderedSet {
private:
	size_t theSize;
	BinarySearchTree<Comparable> tree;

public:
	OrderedSet() :theSize(0) {
	}

	~OrderedSet() {
		clear();
	}

	OrderedSet(const OrderedSet& s) : tree(s.tree), theSize(s.theSize) {
	}

	void clear() {
		tree.makeEmpty();
		theSize = 0;
	}

	size_t size() const {
		return theSize;
	}

	bool empty() const {
		if (theSize == 0) {
			return true;
		}
		return false;
	}

	void push(const Comparable& t) {
		if (tree.insert(t) != tree.find(t)) {
			++theSize;
		}
	}

	friend class BinarySearchTree<Comparable>;
	typedef typename BinarySearchTree<Comparable>::iterator iterator;

	iterator begin() const {
		return tree.findMin();
	}

	iterator end() const {
		return tree.findMax();
	}

	iterator insert(const Comparable& t) {
		if (tree.insert(t) != tree.find(t)) {
			++theSize;
		}
		return tree.insert(t);
	}
	iterator find(const Comparable& t) {
		auto it = tree.find(t);
		if (it == nullptr) {
			return end();
		}
		else
		{
			return it;
		}

	}

	iterator erase(iterator& itr) {
		if (itr == end()) {
			return itr;
		}
		iterator next = itr;
		tree.remove(*itr);
		--theSize;
		itr = end();
		return next++;
	}
};
