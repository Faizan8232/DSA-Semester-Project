#include"Double LinkList.h"
#include<iostream>
#include<conio.h>
using namespace std;
/////////////////////////////Node///////////////////////////
Node::Node()
{
	data = 0;
	next = NULL;
	prev = NULL;
}
Node::Node(int Data)
{
	data = Data;
	next = NULL;
	prev = NULL;
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
Node* Node::getPrev()
{
	return this->prev;
}
void Node::setPrev(Node* prev)
{
	this->prev = prev;
}
////////////////////////////////////DoubleLinkList/////////////////////////////
DoubleLinkList::DoubleLinkList()
{
	this->Head = NULL;
	this->Tail = NULL;
}
Node* DoubleLinkList::getHead()
{
	return this->Head;
}
Node* DoubleLinkList::getTail()
{
	return this->Tail;
}
void DoubleLinkList::setHead(Node* Head)
{
	this->Head = Head;
}
void DoubleLinkList::setTail(Node* Tail)
{
	this->Tail = Tail;
}
bool DoubleLinkList::IsEmpty()
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
void DoubleLinkList::InsertAtHead(int data)
{
	Node* temp = new Node(data);
	if (IsEmpty() == true)
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
void DoubleLinkList::InsertAtTail(int data)
{
	Node* temp = new Node(data);
	if (IsEmpty() == true)
	{
		Head = temp;
		Tail = temp;
	}
	else
	{
		Tail->setNext(temp);
		temp->setPrev(Tail);
		Tail = temp;
	}

}
void DoubleLinkList::search(int data)
{
	Node* temp = Head;
	while (temp != NULL)
	{
		if (temp->getData() == data)
		{
			cout << temp->getData();
			break;
		}
		temp = temp->getNext();
	}
}
Node* DoubleLinkList::searchForDelete(int toFind)
{
	Node* temp = Head;
	while (temp != NULL)
	{
		if (temp->getData() == toFind)
		{
			return temp;
		}
		temp = temp->getNext();
	}
	return NULL;
}
void DoubleLinkList::deletion(int data)
{
	Node* toDelete = searchForDelete(data);
	if (toDelete == NULL)
	{
		cout << "No Data Found" << endl;
	}
	else
	{
		if (toDelete == Head)
		{
			Node* next = Head->getNext();
			Head = next;
			delete toDelete;
		}
		else if (toDelete == Tail)
		{
			Node* prev = Tail->getPrev();
			prev->setNext(NULL);
			Tail = prev;
			delete toDelete;
		}
		else
		{
			Node* prev = toDelete->getPrev();
			Node* next = toDelete->getNext();
			prev->setNext(next);
			next->setPrev(prev);
			delete toDelete;
		}
	}

}
void DoubleLinkList::Display()
{
	Node* temp = Head;
	while (temp != NULL)
	{
		cout << temp->getData() << endl;
		temp = temp->getNext();
	}
}
void DoubleLinkList::insertAtTarget(int target, int data)
{
	Node* TargetToReplace = searchForDelete(target);
	Node* temp = new Node(data);
	if (TargetToReplace == NULL)
	{
		cout << "Target Not Found" << endl;
	}
	else if (TargetToReplace == Head)
	{
		temp->setNext(Head);
		Head->setPrev(temp);
		Head = temp;
	}
	else if (TargetToReplace == Tail)
	{
		Node* prev = TargetToReplace->getPrev();
		Tail->setPrev(prev);
		Tail->setNext(temp);
		Tail = temp;
	}
	else
	{
		Node* prev = TargetToReplace->getPrev();
		Node* next = TargetToReplace->getNext();
		prev->setNext(temp);
		temp->setPrev(prev);
		temp->setNext(TargetToReplace);
		next->setPrev(temp);
	}
}