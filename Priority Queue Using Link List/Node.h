#pragma once
class Node
{
private:
	int data;
	int key;
	Node* next;
public:
	Node();
	Node(int,int);
	int getKey();
	int getData();
	Node* getNext();
	void setData(int data);
	void setKey(int key);
	void setNext(Node*);
};