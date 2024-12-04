#include<iostream>
#include<conio.h>
using namespace std;
class Array
{
private:
	int size;
	string *arra;
	int counter;
public:
	Array()
	{
		size = 2;
		arra = new string[size];
		counter = 0;
	}
	void insertion(string data)
	{
		if (counter != size)
		{
			arra[counter++] = data;
			cout << "Inserted" << endl;
		}
		else
		{
			resize();
			arra[counter++] = data;
			cout << "Inserted" << endl;

		}

	}
	void resize()
	{
		string* array2 = new string[size * 2];
		for (int i = 0;i < size;i++)
		{
			array2[i] = arra[i];
		}
		delete[] arra;
		arra = array2;
		size = size * 2;
	}
	void display()
	{
		for (int i = 0;i < counter;i++)
		{
			cout << arra[i] << endl;
		}
	}
	void search(string data)
	{
		for (int i = 0;i < counter;i++)
		{
			if (arra[i] == data)
			{
				cout<<data << "  Found" << endl;
				return;
			}
				
			
		}
		cout << "Data Not Found" << endl;
		return;
		
	}
	void del(string data)
	{
		for (int i = 0; i < counter; i++)
		{
			if (arra[i] == data)
			{
				for (int j = i; j < counter - 1; j++)
				{
					arra[j] = arra[j + 1];
				}
				counter--; 
				arra[counter] = ""; 
				cout << "Deleted" << endl;
				return;
			}
		}
		cout << "Data Not Found" << endl;
	}
	void menu()
	{
		int select;
		do
		{
			system("CLS");
			cout << "Enter Data(Exit For Exit)" << endl;
			cout << "1 For Entry" << endl;
			cout << "2 For Search" << endl;
			cout << "3 For Delete" << endl;
			cout << "4 For Display" << endl;
			cin >> select;
			switch (select)
			{
			case 1:
			{
				string data;
				cout << "Enter Your Data" << endl;
				cin >> data;
				insertion(data);
				cout << "Press 5 For Menue" << endl;
				cin >> select;

			}
			break;
			case 2:
			{
				string data;
				cout << "Enter Your Data" << endl;
				cin >> data;
				search(data);
				cout << "Press 5 For Menue" << endl;
				cin >> select;
			}
			break;
			case 3:
			{
				string data;
				cout << "Enter Your Data" << endl;
				cin >> data;
				del(data);
				cout << "Press 5 For Menue" << endl;
				cin >> select;

			}
			break;
			case 4:
			{
				display();
				cout << "Press 5 For Menue" << endl;
				cin >> select;
			}
			break;
			default:
			{
				cout << "Invalid Input" << endl;
			}
			break;

			}
			
		} while (select != 0);
		return;

	}
};
int main()
{
	Array demo;
	demo.menu();
	system("pause");
	return 0;
}