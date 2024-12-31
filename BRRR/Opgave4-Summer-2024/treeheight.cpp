
#include <iostream>

using namespace std;


struct AVLNode {
	int val;
	AVLNode* parent;
	AVLNode* left;
	AVLNode* right;
	AVLNode(int x) {
		val = x; parent = nullptr;
		left = nullptr; right = nullptr;
	}
};

int height(AVLNode* root) {
	if (root == nullptr) {
		return 0;
	}
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	return 1 + max(leftHeight, rightHeight);
}	

int main(){
	AVLNode* root = new AVLNode(17);
	root->left = new AVLNode(10);
	root->right = new AVLNode(33);
	root->left->left = new AVLNode(8);
	root->left->right = new AVLNode(12);
	cout << "Height of the tree is: " << height(root) << endl;
	return 0;
}