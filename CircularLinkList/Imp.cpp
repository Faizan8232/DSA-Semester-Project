#include"CircularLinkList.h"
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
////////////////////////////////////CircularLinkList/////////////////////////////
CircularLinkList::CircularLinkList()
{
	this->Head = NULL;
	this->Tail = NULL;
}
Node* CircularLinkList::getHead()
{
	return this->Head;
}
Node* CircularLinkList::getTail()
{
	return this->Tail;
}
void CircularLinkList::setHead(Node* Head)
{
	this->Head = Head;
}
void CircularLinkList::setTail(Node* Tail)
{
	this->Tail = Tail;
}
bool CircularLinkList::IsEmpty()
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
void CircularLinkList::InsertAtHead(int data)
{
	Node* temp = new Node(data);
	if (IsEmpty() == true)
	{
		Head = temp;
		Tail = temp;
		Tail->setNext(Head);
	}
	else
	{
		temp->setNext(Head);
		Head = temp;
	}
}
void CircularLinkList::InsertAtTail(int data)
{
	Node* temp = new Node(data);
	if (IsEmpty() == true)
	{
		Head = temp;
		Tail = temp;
		Tail->setNext(Head);
	}
	else
	{
		Tail->setNext(temp);
		temp->setNext(Head);
		Tail = temp;
	}

}
void CircularLinkList::search(int data)
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
}
Node* CircularLinkList::searchForDelete(int toFind)
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
void CircularLinkList::deletion(int data)
{
	Node* toDelete = searchForDelete(data);
	if (toDelete == NULL)
	{
		cout << "No Data Found" << endl;
	}
	else
	{
		Node* current = Head;
		Node* prev = NULL;
		do
		{
			if (current->getData() == data)
			{
				break;
			}
			prev = current;
			current = current->getNext();

		} while (current != Head);
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
			Tail->setNext(Head);
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
void CircularLinkList::Display()
{
	Node* temp = Head;
	do
	{
		if (Head == NULL)
		{
			cout << "List Is Empty" << endl;
			break;
		}
		cout << temp->getData()<<endl;
		temp = temp->getNext();

	} while (temp != Head);
}
void CircularLinkList::insertAtTarget(int target, int data)
{
	Node* TargetToReplace = searchForDelete(target);
	Node* temp = new Node(data);
	if (TargetToReplace == Head)
	{
		temp->setNext(Head);
		Head = temp;
	}
	else if (TargetToReplace == Tail)
	{
		Tail->setNext(temp);
		temp->setNext(Head);
		Tail = temp;
	}
	else
	{
		Node* current = Head;
		Node* prev = NULL;
		do
		{
			if (current->getData() == target)
			{
				break;
			}
			prev = current;
			current = current->getNext();

		} while (temp != Head);
		prev->setNext(temp);
		temp->setNext(current);

	}
}