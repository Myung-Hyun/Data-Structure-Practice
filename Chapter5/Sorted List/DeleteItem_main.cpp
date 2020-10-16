#include <iostream>
#include "SortedType.h"

using namespace std;


int main()
{
	SortedType<int> list1;

	list1.InsertItem(5);
	list1.InsertItem(2);
	list1.InsertItem(3);
	list1.InsertItem(2);
	list1.InsertItem(4);
	list1.InsertItem(0);

	list1.ResetList();
	int item;

	list1.DeleteItem_b(2);

	for (int i = 0; i < 7;i++)
	{
		list1.GetNextItem(item);
		cout << item << " ";
	}
	return 0;
}


