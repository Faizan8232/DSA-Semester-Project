#include"StackLinkList.h"
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	StackLinkList one;
	one.Push(100);
	one.Push(200);
	one.Push(300);
	one.Push(400);
	one.Pop();
	one.Display();

	system("pause");
	return 0;
}