#include"Queue.h"
#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	Queue demo;
	demo.Enqueue(90,5);
	demo.Enqueue(100, 2);
	demo.Print();
	system("pause");
	return 0;
}