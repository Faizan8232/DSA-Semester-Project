#pragma once
class Node
{
private:
	int data;
	Node* next;
	Node* prev;
public:
	Node();
	Node(int data);
	int getData();
	Node* getNext();
	Node* getPrev();
	void setData(int data);
	void setNext(Node* Next);
	void setPrev(Node* prev);

};
