#include<iostream>
#include<conio.h>
using namespace std;
class CircularQueue
{
private:
	int* arr;
	int counter;
	int rear;
	int front;
	int size;
public:
	CircularQueue(int size)
	{
		arr = new int(size);
		this->size = size;
		counter = 0;
		front = -1;
		rear = -1;
	}

	void Enqueue(int data)
	{
		if (front == -1 && rear == -1)
		{
			front = 0;
			rear = 0;

		}
		else if ((rear + 1) % size == front)
		{
			cout << "Queue Is Full" << endl;
			return;
		}
		else
		{
			rear = (rear + 1) % size;
		}
		arr[rear] = data;
		counter++;

	}
	void Dequeue()
	{
		if (front == -1 && rear == -1)
		{
			cout << "Queue Is Empty" << endl;
			return;
		}
		else if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else
		{
			front = (front + 1) % size;
		}
		counter--;
	}
	void display()
	{
		int i = front;
		while (i != rear)
		{
			cout << arr[i] << endl;
			i = (i + 1) % size;
		}
		cout << arr[rear];
	}
	int getc()
	{
		return counter;
	}
};
int main()
{
	CircularQueue demo(5);
	demo.Enqueue(10);
	demo.Enqueue(20);
	demo.Enqueue(30);
	demo.Enqueue(40);
	demo.Enqueue(50);
	demo.Dequeue();
	cout << "Total Elements:- " << demo.getc() << endl;
	demo.display();


	system("pause");
	return 0;
}