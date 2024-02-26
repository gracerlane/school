// Grace Lane
// 16 May 2022
// BST.cpp

#include <iostream>
#include <string>
#include "BST.h"

using namespace std;
		
BST::TreeNode* BST::insert(TreeNode* t, int x) {
	TreeNode* curr = t;
	TreeNode* newNode = new TreeNode;                // creates a new TreeNode to insert
	newNode->val = x;
	newNode->left = nullptr;
	newNode->right = nullptr;

	if (root == nullptr) {                           // if the tree is empty the root becomes the new node
		root = newNode;
	} else if (x < curr->val) {                      // if the value to be inserted is less than the current node value
		if (curr->left == nullptr) {                   // if the current node left child is empty, it becomes the new node
			curr->left = newNode;
		} else{
			return insert(curr->left, x);                // pass the current node back through the function to find correct placement
		}
	} else if (x > curr->val) {                      // if the value to be inserted is greater than the current node value
		if (curr->right == nullptr) {                  // if the current node left child is empty, it becomes the new node
			curr->right = newNode;
		} else {
			return insert(curr->right, x);               // pass the current node back through the fucntion to find correct placement
		}
	}
	return t;                                        // return the root with the updated tree
}

int BST::search(TreeNode* t, int x) {
	TreeNode* curr = t;

	if (t == nullptr) {                   // if the tree is empty, return 0
		return 0;
	}

	while (curr != nullptr) {             // iterates while curr points to a node
		if (x == curr->val) {               // if the value is found in the tree, return 1
			return 1;
		} else if (x < curr->val) {
			curr = curr->left;
		} else {
			curr = curr->right;
		}
	}

	return -1;                            // if the value is not found in the tree, return -1
}

int BST::predecessor(TreeNode* t, int x) {      // only nodes that are in the tree
	TreeNode* pred = t;
	TreeNode* curr = t;

	if (t == nullptr) {
		return x;
	}

  while (curr->val != x) {                      // iterates until at the node with value x and assigns predecessor as it goes
		if (curr->val < x) {
			pred = curr;
			curr = curr->right;
		}
		if (curr->val > x) {
			curr = curr->left;
		}
	}

	if (curr->left != nullptr) {                  // once it reaches the correct node, then continue until you find the correct predecessor
		curr = curr->left;                          // predecssor is less than the current node
		while (curr->right != nullptr) {            // it is also the largest of the smaller nodes
			curr = curr->right;
		}
		pred = curr;
	} else if (pred->val > curr->val) {           // this is for when the current node doesn't have any more left children, then it won't have a predecessor
		pred = curr;
	}

	return pred->val;                             // returns the predecessor
}

int BST::successor(TreeNode* t, int x) {        // only nodes that are in the tree
	TreeNode* curr = t;
	TreeNode* suc = t;

	if (t == nullptr) {
		return x;
	}

  while (curr->val != x) {                      // iterates until at the node with value x and assigns the sucessor as it goes
		if (curr->val > x) {
				suc = curr;
				curr = curr->left;
		}
		if (curr->val < x) {
			curr = curr->right;
		}
	}

	if (curr->right != nullptr) {                 // once it reaches the correct node, then continue until you find the correct sucessor
		curr = curr->right;                         // sucessor is greater than the current node
		while (curr->left != nullptr) {             // it is also the smallest of the larger nodes
			curr = curr->left;
		}
		suc = curr;
	} else if (suc->val < curr->val) {            // this is for when the current node doesn't have any more right children, then it won't have a sucessor
		suc = curr;
	}

	return suc->val;                              // returns the successor
} 

int BST::height(TreeNode* t) {          // returns the height of the tree by finding the max height between the left and right subtrees recursively
	if (t == nullptr) {
		return -1;
	} else if (t->left == nullptr && t->right == nullptr) {
		return 1;
	} else {
		return 1 + max(height(t->left), height(t->right));
	}
}

int BST::total(TreeNode* t) {          // returns the total number of nodes by adding up the amounts in the left and right subtrees recursively
	if (t == nullptr) {
		return 0;
	} else {
		return 1 + total(t->left) + total(t->right);
	}
}


BST::TreeNode* BST::deleteNode(TreeNode* t, int x) {
	TreeNode* curr = t;

	if (t == nullptr) {
		return t;
	}

	while (curr->val != x) {      // iterates until at the node with value x
		if (curr->val > x) {
				curr = curr->left;
		}
		if (curr->val < x) {
			curr = curr->right;
		}
	}

	delete curr;                  // deletes the node with the specified value

	return t;                     // returns the root of the updated tree

}

void BST::inorder(TreeNode* t) {	     // prints out the tree inorder (LMR)
	if (t == nullptr) {
		return;
	}
	inorder(t->left);
	cout << t->val << " ";
	inorder(t->right);
}

void BST::preorder(TreeNode* t) {	     // prints out the tree preorder (MLR)
	if (t == nullptr) {
		return;
	}
	cout << t->val << " ";
	preorder(t->left);
	preorder(t->right);
}

void BST::postorder(TreeNode* t) {	     // prints out the tree postorder (LRM)
	if (t == nullptr) {
		return;
	}
	postorder(t->left);
	postorder(t->right);
	cout << t->val << " ";
}

int BST::balanced(TreeNode* t) {                                    // checks if the tree is balanced
	int check = 1;

	if (t == nullptr) {                    
		return check;
	} else if (abs(height(t->left)-height(t->right)) > 1) {           // as long as the height of the left subtree minus the 
		check = -1;                                                     // right subtree is greater than 1, the tree isn't balanced
	}
	return check;                                                     // return 1 for balanced and -1 for not balanced
}

BST::TreeNode* BST::destroy(TreeNode* t) {          // detroys the entire tree by setting every node to nullptr
	if (t) {
		destroy(t->left);
		destroy(t->right);
		t = nullptr;
	}
	root = nullptr;                                   // sets the root to nullptr and then returns the empty tree
	return root;
}

// constructor sets the root to nullptr
BST::BST() {
	root = nullptr;
}

// all the following are public functions that are called in main() and then call the related private functions
void BST::insertNode(int x) {
	insert(root, x);
}
int BST::searchNode(int x) {
	return search(root, x);
}
int BST::predNode(int x) {
	return predecessor(root, x);
}
int BST::successNode(int x) {
	return successor(root, x);
}
int BST::heightTree() {
	return height(root);
}
int BST::totalNodes() {
	return total(root);
}
void BST::deleteANode(int x) {
	deleteNode(root, x);
}
void BST::inorderDisplay() {
	inorder(root);
}
void BST::preorderDisplay() {
	preorder(root);
}
void BST::postorderDisplay() {
	postorder(root);
}
int BST::balancedTree() {
	return balanced(root);
}
BST::TreeNode* BST::destroyTree() {
	return destroy(root);
}
