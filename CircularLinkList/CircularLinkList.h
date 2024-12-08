#pragma once
#include"Node.h"
class CircularLinkList
{
private:
	Node* Head;
	Node* Tail;
public:
	CircularLinkList();
	Node* getHead();
	Node* getTail();
	void setHead(Node*);
	void setTail(Node*);
	bool IsEmpty();
	void InsertAtHead(int data);
	void InsertAtTail(int data);
	void insertAtTarget(int, int);
	void search(int data);
	Node* searchForDelete(int);
	void deletion(int data);
	void Display();

};