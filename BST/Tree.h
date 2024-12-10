#include"TreeNode.h"
class Tree
{
private:
	TreeNode* root;
public:
	Tree();
	bool isEmpty();
	void insert(int);
	TreeNode* search(int);
	TreeNode* findPlace(int);
	void display();
	void inorder(TreeNode* root);
	void RemoveNode(int key);
};