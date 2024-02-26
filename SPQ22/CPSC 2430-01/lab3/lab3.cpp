// Grace Lane
// 6 May 2022
// lab3.cpp
// Revised code given by instructor

#include <iostream>

using namespace std;


class BST {
	private:    
		struct TreeNode {
			int val;
			TreeNode* left;
			TreeNode* right;
		};
		TreeNode* root;
		// For this lab, you do not need to consider the situation when inserting the same values.
		// Only insert different values when you test your program in the main function.
		TreeNode* insert(TreeNode * t, int x) {
			TreeNode* previous;
			TreeNode *current;
			TreeNode* newNode;

			newNode = new TreeNode; 
			newNode->val = x;
			newNode->left = nullptr;
			newNode->right = nullptr;

			if (t == nullptr) {
				t = newNode;
				newNode->left = nullptr;
				newNode->right = nullptr;
			} else {
				current = t;
				previous = nullptr;
				while (current != nullptr && newNode->val < current->val) {
					previous = current;
					current = current->left;
				}
				while (current != nullptr && newNode->val > current->val) {
					previous = current;
					current = current->right;
				}
				if (newNode->val < previous->val) {
					previous->left = newNode;
				} else {
					previous->right = newNode;
				}
			}
			return t;
		}
		void inorder(TreeNode * t) {
			if (t == nullptr) {
				return;
			}
			inorder(t->left);
			cout << t->val << " ";
			inorder(t->right);
		}
		void preorder(TreeNode * t) {
			if (t == nullptr) {
				return;
			}
			cout << t->val << " ";
			preorder(t->left);
			preorder(t->right);
		}
		void postorder(TreeNode * t) {
			if (t == nullptr) {
				return;
			}
			postorder(t->left);
			postorder(t->right);
			cout << t->val << " ";
		}

	public:
		BST() {
			root = nullptr;
		}
		void insertNode(int x) {
			root = insert(root, x);
		}
		void inorderDisplay() {
			inorder(root);
		}
		void preorderDisplay() {
			preorder(root);
		}
		void postorderDisplay() {
			postorder(root);
		}
};

// in your main function, test your implementations. For example,  
int main() 
{
	BST t;

	t.insertNode(45);
	t.insertNode(3);
	t.insertNode(29);
	t.insertNode(30);
	t.insertNode(9);

	cout << endl;

	// inorder display
	cout << "Inorder: ";
	t.inorderDisplay();  // the output should be: 7, 9, 10, 29, 30
	cout << endl << endl;

	// preorder display
	cout << "Preorder: ";
	t.preorderDisplay();  // the output should be: 10, 7, 9, 29, 30
	cout << endl << endl;

	// postorder display
	cout << "Postorder: ";
	t.postorderDisplay();  // the output should be: 9, 7, 30, 29, 10
	cout << endl << endl;

	return 0; 
}