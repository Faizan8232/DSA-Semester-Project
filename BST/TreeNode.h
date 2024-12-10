#pragma once
class TreeNode
{
private:
	int key;
	TreeNode* left;
	TreeNode* right;
public:
	TreeNode();
	TreeNode(int);
	int getKey();
	void setKey(int);
	TreeNode* getLeft();
	void setLeft(TreeNode*);
	TreeNode* getRight();
	void setRight(TreeNode*);
};
