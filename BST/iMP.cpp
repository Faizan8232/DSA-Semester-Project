#include"Tree.h"
#include<iostream>
#include<conio.h>
using namespace std;
TreeNode::TreeNode()
{
	this->key = -1;
	this->left = NULL;
	this->right = NULL;
}
TreeNode::TreeNode(int data)
{
	this->key = data;
	this->left = NULL;
	this->right = NULL;
}
int TreeNode::getKey()
{
	return this->key;
}
void TreeNode::setKey(int key)
{
	this->key = key;
}
TreeNode* TreeNode::getLeft()
{
	return this->left;
}
void TreeNode::setLeft(TreeNode* left)
{
	this->left = left;
}
TreeNode* TreeNode::getRight()
{
	return this->right;
}
void TreeNode::setRight(TreeNode* right)
{
	this->right = right;
}
Tree::Tree()
{
	this->root = NULL;
}
bool Tree::isEmpty()
{
	if (root == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
TreeNode* Tree::findPlace(int key)
{
	TreeNode* temp = root;
	TreeNode* parent = NULL;
	while (temp != NULL)
	{
		if (temp->getKey() == key)
		{
			return NULL;
		}
		else if (temp->getKey() > key)
		{
			parent = temp;
			temp = temp->getLeft();
		}
		else if (temp->getKey() < key)
		{
			parent = temp;
			temp = temp->getRight();
		}
	}
	return parent;
}
void Tree::insert(int key)
{
	if (isEmpty())
	{
		TreeNode* newNode = new TreeNode(key);
		root = newNode;
	}
	else
	{
		TreeNode* parent = findPlace(key);
		if (parent == NULL)
		{
			cout << "Duplication NOt Allowed" << endl;
			return;
		}
		else
		{
			TreeNode* newNode = new TreeNode(key);
			if (parent->getKey() > key)
			{
				parent->setLeft(newNode);
			}
			else if (parent->getKey() < key)
			{
				parent->setRight(newNode);
			}
		}
	}
}

void Tree::display()
{
	inorder(root);
}
void Tree::inorder(TreeNode* n)
{
	if (n != NULL)
	{
		inorder(n->getLeft());
		cout << n->getKey() << endl;
		inorder(n->getRight());
	}
}
TreeNode* Tree::search(int key)
{
	TreeNode* temp = root;
	while (temp != NULL)
	{
		if (temp->getKey() == key)
		{
			return temp;
		}
		else if (temp->getKey() > key)
		{
			temp = temp->getLeft();
		}
		else
		{
			temp = temp->getRight();
		}
	}
	return NULL;
}
void Tree::RemoveNode(int key)
{
	TreeNode* temp = root;
	TreeNode* parent=NULL;
	while (temp != NULL)
	{
		if (temp->getKey() == key)
		{
			break;
		}
		else if (temp->getKey() > key)
		{
			parent = temp;
			temp = temp->getLeft();
		}
		else
		{
			parent = temp;
			temp = temp->getRight();
		}
	}
	if (temp == NULL)
	{
		cout << "Value Not Found" << endl;
		return;
	}

	if (temp->getRight() == NULL && temp->getLeft() == NULL)
	{
		if (parent->getRight() != NULL)
		{
			parent->setRight(NULL);
		}
		else
		{
			parent->setLeft(NULL);
		}
		delete temp;
	}
	else if (temp->getRight() == NULL || temp->getLeft() == NULL)
	{
		if (parent->getRight() == temp)
		{
			if (temp->getRight() != NULL)
			{
				parent->setRight(temp->getRight());
			}
			else
			{
				parent->setRight(temp->getLeft());
			}
			delete temp;
		}
		else if (parent->getLeft() == temp)
		{
			if (temp->getLeft() != NULL)
			{
				parent->setLeft(temp->getLeft());
			}
			else
			{
				parent->setLeft(temp->getRight());
			}
			delete temp;
		}
	}
	else
	{
		TreeNode* RightParent = temp;
		TreeNode* Right = temp->getRight();
		while (Right->getLeft() != NULL)
		{
			RightParent = Right;
			Right = Right->getLeft();
		}
		temp->setKey(Right->getKey());
		if (RightParent->getLeft() == Right)
		{
			RightParent->setLeft(Right->getRight());
		}
		else
		{
			RightParent->setRight(Right->getRight());
		}
		delete Right;
	}
}