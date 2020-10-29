#include <iostream>
#include "SortedType.h"
using namespace std;

int main()
{
	
	SortedType<char> list;

	list.InsertItem('X');
	list.InsertItem('Y');
	list.InsertItem('Z');

	list.PrintReverse();

	/*
	char temp='A';
	
	list.ResetList();
	for (int i = 0; i < 3; i++)
	{
		list.GetNextItem(temp);
		cout << temp;
	}
	*/

	


	return 0;
}
