#include"DoubleCircularLinkList.h"
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
////////////////////////////////////DoubleCircularLinkList/////////////////////////////
DoubleCircularLinkList::DoubleCircularLinkList()
{
	this->Head = NULL;
	this->Tail = NULL;
}
Node* DoubleCircularLinkList::getHead()
{
	return this->Head;
}
Node* DoubleCircularLinkList::getTail()
{
	return this->Tail;
}
void DoubleCircularLinkList::setHead(Node* Head)
{
	this->Head = Head;
}
void DoubleCircularLinkList::setTail(Node* Tail)
{
	this->Tail = Tail;
}
bool DoubleCircularLinkList::IsEmpty()
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
void DoubleCircularLinkList::InsertAtHead(int data)
{
	Node* temp = new Node(data);
	if (IsEmpty() == true)
	{
		Head = temp;
		Tail = temp;
		Head->setPrev(Tail);
		Tail->setNext(Head);
	}
	else
	{
		temp->setNext(Head);
		temp->setPrev(Tail);
		Head = temp;
		Tail->setNext(Head);
		
	}
}
void DoubleCircularLinkList::InsertAtTail(int data)
{
	Node* temp = new Node(data);
	if (IsEmpty() == true)
	{
		Head = temp;
		Tail = temp;
		Head->setPrev(Tail);
		Tail->setNext(Head);
	}
	else
	{
		Tail->setNext(temp);
		temp->setPrev(Tail);
		Tail = temp;
		Tail->setNext(Head);
	}

}
void DoubleCircularLinkList::search(int data)
{
	Node* temp = Head;
	do
	{
		if (temp->getData() == data)
		{
			cout << temp->getData();
			break;
		}
		temp = temp->getNext();
	} while (temp != Head);
	cout << "No Data Found" << endl;
}
Node* DoubleCircularLinkList::searchForDelete(int toFind)
{
	Node* temp = Head; 
	do
	{
		if (temp->getData() == toFind)
		{
			return temp;
		}
		temp = temp->getNext();
	} while (temp != Head);
	return NULL;
}
void DoubleCircularLinkList::deletion(int data)
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
			Head->setPrev(Tail);
			Tail->setNext(Head);
			delete toDelete;
		}
		else if (toDelete == Tail)
		{
			Node* prev = Tail->getPrev();
			prev->setNext(Head);
			Head->setPrev(prev);
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
void DoubleCircularLinkList::Display()
{
	Node* temp = Head;
	do
	{
		cout << temp->getData() << endl;
		temp = temp->getNext();
	} while (temp != Head);
}
void DoubleCircularLinkList::insertAtTarget(int target, int data)
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
		temp->setPrev(Tail);
		Head->setPrev(temp);
		Head = temp;
	}
	else if (TargetToReplace == Tail)
	{
		Tail->setNext(temp);
		Tail = temp;
		Tail->setNext(Head);
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