// Grace Lane
// 16 May 2022
// BST.h

#include <iostream>

using namespace std;

#ifndef BST_H       
#define BST_H
class BST {
	private:    
		struct TreeNode {
			int val;
			TreeNode* left;
			TreeNode* right;
		};
		TreeNode* root;
		
		TreeNode* insert(TreeNode* t, int x);
		int search(TreeNode* t, int x);
		int predecessor(TreeNode* t, int x);
		int successor(TreeNode* t, int x);
		int height(TreeNode* t);
		int total(TreeNode* t);
		TreeNode* deleteNode(TreeNode* t, int x);
		void inorder(TreeNode* t);
		void preorder(TreeNode* t);
		void postorder(TreeNode* t);
		int balanced(TreeNode* t);
		TreeNode* destroy(TreeNode* t);

	public:
		BST();
		void insertNode(int x);
		int searchNode(int x);
		int predNode(int x);
		int successNode(int x);
		int heightTree();
		int totalNodes();
		void deleteANode(int x);
		void inorderDisplay();
		void preorderDisplay();
		void postorderDisplay();
		int balancedTree();
		TreeNode* destroyTree();
};
#endif