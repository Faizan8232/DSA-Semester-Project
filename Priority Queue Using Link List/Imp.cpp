#include"Queue.h"
#include<iostream>
#include<conio.h>
using namespace std;
///////////////////////////Node//////////////////////////
Node::Node()
{
    this->data = 0;
    this->key = 0;
    this->next = NULL;
}
Node::Node(int data, int key)
{
    this->data = data;
    this->key = key;
    this->next = NULL;
}
int Node::getKey()
{
    return this->key;
}

int Node::getData()
{
    return this->data;
}

Node* Node::getNext()
{
    return this->next;
}

void  Node::setData(int data)
{
    this->data = data;
}

void Node::setKey(int key)
{
    this->key = key;
}

void Node::setNext(Node* next)
{
    this->next = next;
}
/////////////////////////////////Queue//////////////////////////////////////////////////
Queue::Queue()
{
    this->Front = NULL;
    this->Rear = NULL;
}
bool Queue::IsEmpty()
{
    if (Front == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Queue::Enqueue(int data, int key)
{
    if (IsEmpty())
    {
        Node* temp = new Node(data, key);
        Front = temp;
        Rear = temp;
    }
    else
    {
        Node* temp = new Node(data, key);
        Rear->setNext(temp);
        Rear = temp;
        sort();
    }
}
void Queue::DeQueue()
{
    if (IsEmpty())
    {
        cout << "Queue is Empty" << endl;
        return;
    }
    Node* temp = Front;
    Front = Front->getNext();
    delete temp;
   
}
void Queue::Print()
{
    Node* temp = Front;
    while (temp != NULL)
    {
        cout << temp->getData();
        temp = temp->getNext();
    }
}
void Queue::sort()
{
    
    for (Node *temp = Front;temp != NULL;temp = temp->getNext())
    {
        for (Node* temp2 = temp->getNext();temp2 != NULL;temp2 = temp2->getNext())
        {
            if (temp2->getKey() < temp->getKey())
            {
                swap(temp, temp2);
            }
        }
    }
}
void Queue::swap(Node* current, Node* next)
{
    int tempData = current->getData();
    int tempKey = current->getKey();
    current->setData(next->getData());
    current->setKey(next->getKey());
    next->setData(tempData);
    next->setKey(tempKey);
}
