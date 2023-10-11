// C++ code to implement morris traversal approach
#include <iostream>
using namespace std;

// Definition for a binary tree node
struct Node {
	int val;
	Node* left;
	Node* right;
	Node(int x) : val(x), left(NULL), right(NULL) {}
};

// function to count the number of nodes in a binary tree using Morris traversal
int countNodes(Node* root) {
	int count = 0;
	Node* current = root;
	while (current != NULL) {
		// if the current node has no left child, increment the count and move to the right child
		if (current->left == NULL) {
			count++;
			current = current->right;
		}
		else {
			// find the rightmost node in the left subtree of the current node
			Node* predecessor = current->left;
			while (predecessor->right != NULL && predecessor->right != current) {
				predecessor = predecessor->right;
			}
			if (predecessor->right == NULL) {
				// set the right child of the rightmost node to the current node
				predecessor->right = current;
				// move to the left child of the current node
				current = current->left;
			}
			else {
				// restore the right child of the rightmost node to NULL
				predecessor->right = NULL;
				// increment the count for the current node
				count++;
				// move to the right child of the current node
				current = current->right;
			}
		}
	}
	// return the count of nodes in the binary tree
	return count;
}
// Driver Code
int main() {
	// create binary tree
	Node* root = new Node(1);
	root->left = new Node(10);
	root->right = new Node(39);
	root->left->left = new Node(5);

	// count nodes using Morris traversal
	int nodeCount = countNodes(root);

	// print the result
	cout << "The size of binary tree is: " << nodeCount << endl;

	return 0;
}
// This code is contributed by Veerendra_Singh_Rajpoot
