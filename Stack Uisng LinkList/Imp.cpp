#include"StackLinkList.h"
#include<iostream>
#include<conio.h>
using namespace std;
/////////////////////////////Node///////////////////////////
Node::Node()
{
	data = 0;
	next = NULL;
}
Node::Node(int Data)
{
	data = Data;
	next = NULL;
}
int Node::getData()
{
	return this->data;
}
Node* Node::getNext()
{
	return this->next;
}
void Node::setData(int Data)
{
	this->data = data;
}
void Node::setNext(Node* next)
{
	this->next = next;
}
////////////////////////////////////StackLinkList/////////////////////////////
StackLinkList::StackLinkList()
{
	this->Head = NULL;
	this->Tail = NULL;
}
Node* StackLinkList::getHead()
{
	return this->Head;
}
Node* StackLinkList::getTail()
{
	return this->Tail;
}
void StackLinkList::setHead(Node* Head)
{
	this->Head = Head;
}
void StackLinkList::setTail(Node* Tail)
{
	this->Tail = Tail;
}
bool StackLinkList::IsEmpty()
{
	if (Head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void StackLinkList::Push(int data)
{
	Node* temp = new Node(data);
	if (IsEmpty())
	{
		Head = temp;
		Tail = temp;
	}
	else
	{
		temp->setNext(Head);
		Head = temp;
	}
}
void StackLinkList::Pop()
{
	Node* next = Head->getNext();
	delete Head;
	Head = next;
	
}
void StackLinkList::Display()
{
	Node* temp = Head;
	while (temp != NULL)
	{
		cout << temp->getData() << endl;
		temp = temp->getNext();
	}
}
