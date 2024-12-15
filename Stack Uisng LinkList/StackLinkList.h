#pragma once
#include"Node.h"
class StackLinkList
{
private:
	Node* Head;
	Node* Tail;
public:
	StackLinkList();
	Node* getHead();
	Node* getTail();
	void setHead(Node*);
	void setTail(Node*);
	bool IsEmpty();
	void Push(int data);
	void Pop();
	void Display();

};
