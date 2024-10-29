/**
 * Find the smallest item in the tree.
 * Throw UnderflowException if empty.
 */
template<typename Comparable>
const Comparable& AvlTree<Comparable>::findMin() const {
	if (isEmpty()) throw underflow_error("tree is empty.");
	 return findMin(root)->element;
}

/**
 * Find the largest item in the tree.
 * Throw UnderflowException if empty.
 */
template<typename Comparable>
const Comparable& AvlTree<Comparable>::findMax() const {
	if (isEmpty()) throw underflow_error("tree is empty.");
	 return findMax(root)->element;
}

/**
 * Returns true if x is found in the tree.
 */
template<typename Comparable>
bool AvlTree<Comparable>::contains(const Comparable & x) const {
	return contains(x, root);
}

/**
 * Test if the tree is logically empty.
 * Return true if empty, false otherwise.
 */
template<typename Comparable>
bool AvlTree<Comparable>::isEmpty() const {
	return root == nullptr;
}

/**
 * Print the tree contents in sorted order.
 */
template<typename Comparable>
void AvlTree<Comparable>::printTree(ostream& out) const {
	if (isEmpty())
		cout << "Empty tree" << endl;
	else
		printTree(root);
}

/**
 * Make the tree logically empty.
 */
template<typename Comparable>
void AvlTree<Comparable>::makeEmpty() {
	makeEmpty(root);
}

/**
 * Insert x into the tree; duplicates are ignored.
 */
template<typename Comparable>
void AvlTree<Comparable>::insert(const Comparable & x) {
	insert(x, root);
}

/**
 * Remove x from the tree. Nothing is done if x is not found.
 */
template<typename Comparable>
void AvlTree<Comparable>::remove(const Comparable & x) {
	remove(x, root);
}
