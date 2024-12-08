#include"LinkList.h"
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
////////////////////////////////////LinkList/////////////////////////////
LinkList::LinkList()
{
	this->Head = NULL;
	this->Tail = NULL;
}
Node* LinkList::getHead()
{
	return this->Head;
}
Node* LinkList::getTail()
{
	return this->Tail;
}
void LinkList::setHead(Node* Head)
{
	this->Head = Head;
}
void LinkList::setTail(Node* Tail)
{
	this->Tail = Tail;
}
bool LinkList::IsEmpty()
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
void LinkList::InsertAtHead(int data)
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
void LinkList::InsertAtTail(int data)
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
		Tail = temp;
	}

}
void LinkList::search(int data)
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
Node* LinkList::searchForDelete(int toFind)
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
void LinkList::deletion(int data)
{
	Node *toDelete=searchForDelete(data);
	if (toDelete == NULL)
	{
		cout << "No Data Found" << endl;
	}
	else
	{
		Node* current = Head;
		Node* prev = NULL;
		while (current != NULL)
		{
			if (current->getData() == data)
			{
				break;
			}
			prev = current;
			current = current->getNext();
		}
		if (toDelete == Head)
		{
			Node* next = Head->getNext();
			Head = next;
			delete toDelete;
		}
		else if (toDelete == Tail)
		{
			prev->setNext(NULL);
			Tail = prev;
			delete toDelete;
		}
		else
		{
			Node* next = current->getNext();
			prev->setNext(next);
			delete toDelete;
		}
	}
	
}
void LinkList::Display()
{
	Node* temp = Head;
	while (temp != NULL)
	{
		cout << temp->getData() << endl;
		temp = temp->getNext();
	}
}
void LinkList::insertAtTarget(int target, int data)
{
	Node* TargetToReplace = searchForDelete(target);
	Node * temp = new Node(data);
	if (TargetToReplace == Head)
	{
		temp->setNext(Head);
		Head = temp;
	}
	else if (TargetToReplace == Tail)
	{
		Tail->setNext(temp);
		Tail = temp;
	}
	else
	{
		Node* current = Head;
		Node* prev = NULL;
		while (current != NULL)
		{
			if (current->getData() == target)
			{
				break;
			}
			prev = current;
			current = current->getNext();
		}
		prev->setNext(temp);
		temp->setNext(current);

	}
}