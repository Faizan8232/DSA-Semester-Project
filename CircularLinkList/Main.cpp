#include"CircularLinkList.h"
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	CircularLinkList one;
	one.InsertAtHead(34);
	one.InsertAtTail(100);
	one.InsertAtTail(1000);
	one.InsertAtHead(1);
	one.deletion(1000);
	one.Display();

	system("pause");
	return 0;
}