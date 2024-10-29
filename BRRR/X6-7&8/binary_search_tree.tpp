#include "binary_search_tree.h"
/**
 * Returns true if x is found in the tree.
 */
template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable& x) const {
	return contains(x, root) != nullptr;
}

/**
 * Test if the tree is logically empty.
 * Return true if empty, false otherwise.
 */
template<typename Comparable>
bool BinarySearchTree<Comparable>::isEmpty() const {
	return root == nullptr;
}

/**
 * Print the tree contents in sorted order.
 */
template<typename Comparable>
void BinarySearchTree<Comparable>::printTree(ostream& out) const {
	if (isEmpty()) {
		out << "Empty tree" << endl;
	} else
		printTree(root, out);
}

/**
 * Make the tree logically empty.
 */
template<typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty() {
	makeEmpty(root);
}

/**
 * Remove x from the tree. Nothing is done if x is not found.
 */
template<typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable& x) {
	remove(x, root);
}

template<typename Comparable>
const typename BinarySearchTree<Comparable>::iterator BinarySearchTree<Comparable>::findMax() const {
	return iterator(findMax(root));
}


template<typename Comparable>
const typename BinarySearchTree<Comparable>::iterator BinarySearchTree<Comparable>::findMin() const {
	return iterator(findMin(root));
}

template<typename Comparable>
typename BinarySearchTree<Comparable>::iterator BinarySearchTree<Comparable>::insert(const Comparable& x) {
	return iterator(insert(x, root, nullptr));
}

template<typename Comparable>
typename BinarySearchTree<Comparable>::iterator BinarySearchTree<Comparable>::find(const Comparable& x) {
	return iterator(contains(x, root));
}

template<typename Comparable>
typename BinarySearchTree<Comparable>::iterator BinarySearchTree<Comparable>::erase(typename BinarySearchTree<Comparable>::iterator& itr) {
	typename BinarySearchTree<Comparable>::iterator newIterator = itr;
	newIterator++;
	remove(*itr, root);
	itr = nullptr;
	return newIterator;
}
