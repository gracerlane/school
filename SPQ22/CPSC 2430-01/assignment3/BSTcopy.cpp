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
	return t;
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

int BST::predecessor(TreeNode* t, int x) {
	TreeNode* pred = t;
	TreeNode* curr = t;

	if (t == nullptr) {
		return x;
	}

  while (curr->val != x) {      // iterates until at the node with value x
		if (curr->val < x) {
			pred = curr;
			curr = curr->right;
		}
		if (curr->val > x) {
			curr = curr->left;
		}
	}

	if (curr->left != nullptr) {
		curr = curr->left;
		while (curr->right != nullptr) {
			curr = curr->right;
		}
		pred = curr;
	} else if (pred->val > curr->val) {
		pred = curr;
	}

	return pred->val;
}

int BST::successor(TreeNode* t, int x) {
	TreeNode* curr = t;
	TreeNode* suc = t;

	if (t == nullptr) {
		return x;
	}

  while (curr->val != x) {      // iterates until at the node with value x and assigns the sucessor as it goes
		if (curr->val > x) {
				suc = curr;
				curr = curr->left;
		}
		if (curr->val < x) {
			curr = curr->right;
		}
	}

	if (curr->right != nullptr) {
		curr = curr->right;
		while (curr->left != nullptr) {
			curr = curr->left;
		}
		suc = curr;
	} else if (suc->val < curr->val) {
		suc = curr;
	}

	return suc->val;
}

int BST::height(TreeNode* t) {
	if (t == nullptr) {
		return -1;
	} else {
		return 2 + max(height(t->left), height(t->right));
	}
}

int BST::total(TreeNode* t) {
	if (t == nullptr) {
		return 0;
	} else {
		return 1 + total(t->left) + total(t->right);
	}
}


BST::TreeNode* BST::deleteNode(TreeNode* t, int x) {
	TreeNode* temp;

	if (t == nullptr) {
		return t;
	} else if (t->val > x) {
		t->left = deleteNode(t->left, x);
	} else if (t->val < x) {
		t->right = deleteNode(t->right, x);
	} else {	
		if (t->left == nullptr && t->right == nullptr) {
			return nullptr;
		}
		if (t->left == nullptr) {
			TreeNode* temp;
			temp = t;
			t = t->right;
			delete temp;
			return t;
		}
		else if (t->right == nullptr) {
			TreeNode* temp;
			temp = t;
			t = t->left;
			delete temp;
			return t;
		}
		while (t->right) {
			t = t->right;
		}
		TreeNode* temp;
		temp = t;
		t->val = temp->val;
		t->right = deleteNode(t->right, temp->val);
	}
	return t;
}

void BST::inorder(TreeNode* t) {	
	if (t == nullptr) {
		return;
	}
	inorder(t->left);
	cout << t->val << " ";
	inorder(t->right);
}

void BST::preorder(TreeNode* t) {
	if (t == nullptr) {
		return;
	}
	cout << t->val << " ";
	preorder(t->left);
	preorder(t->right);
}

void BST::postorder(TreeNode* t) {
	if (t == nullptr) {
		return;
	}
	postorder(t->left);
	postorder(t->right);
	cout << t->val << " ";
}

int BST::balanced(TreeNode* t) {
	int check = 1;

	if (t == nullptr) {
		return check;
	} else if (abs(height(t->left)-height(t->right)) > 1) {
		check = -1;
	}
	return check;
}

BST::TreeNode* BST::destroy(TreeNode* t) {
	if (t) {
		destroy(t->left);
		destroy(t->right);
		t = nullptr;
	}
	root = nullptr;
	return root;
}


BST::BST() {
	root = nullptr;
}
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

