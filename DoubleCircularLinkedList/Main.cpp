#include"DoubleCircularLinkList.h"
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	DoubleCircularLinkList one;
	one.InsertAtHead(34);
	one.InsertAtTail(100);
	one.InsertAtTail(1000);
	one.InsertAtHead(1);
	one.insertAtTarget(1, 200);  
	//one.deletion(200);
	one.Display();
	system("pause");
	return 0;
}