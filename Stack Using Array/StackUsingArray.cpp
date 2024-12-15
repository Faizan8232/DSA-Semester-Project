#include<iostream>
#include<conio.h>
using namespace std;
class Stack
{
private:
	int* arr;
	int top;
	int count;
	int size;
public:
	Stack(int size)
	{
		arr = new int(size);
		top = -1;
		count = 0;
		this->size = size;
	}
	bool IsEmpty()
	{
		if (count==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isFull()
	{
		if (count == size)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void push(int data)
	{
		if (isFull())
		{
			cout << "Stack  Is Full";
			return;
		}
		arr[++top] = data;
		count++;
	}
	void pop()
	{
		if (IsEmpty())
		{
			cout << "Stack  Is Empty";
			return;
		}
		top--;
		count--;
	}
	void display()
	{
		if (IsEmpty())
		{
			cout << "Stack  Is Empty";
			return;
		}
		for (int i = 0;i <=top;i++)
		{
			cout << arr[i]<<endl;
		}
	}
	int getC()
	{
		return this->count;
	}
};
int main()
{
	Stack demo(10);
	demo.push(9);
	demo.push(8);
	demo.push(7);
	demo.push(6);
	demo.push(5);
	demo.push(4);
	demo.push(3);
	demo.push(2);
	demo.push(1);
	demo.push(100);
	demo.push(100);
	demo.pop();
	demo.display();
	cout << demo.getC() << endl;

	system("pause");
	return 0;
}