#pragma once
#include"Node.h"
class Queue
{
private:
	Node* Front;
	Node* Rear;
public:
	Queue();
	void Enqueue(int,int);
	void DeQueue();
	bool IsEmpty();
	void Print();
	void sort();
	void swap(Node*, Node*);

};
