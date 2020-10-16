#include <iostream>
#include "UnsortedType.h"

using namespace std;

template<class ItemType>
void MergeLists(UnsortedType<ItemType>& list1, UnsortedType<ItemType>& list2, UnsortedType<ItemType>& result);

int main()
{
	UnsortedType<int> list1;

	list1.InsertItem(5);
	list1.InsertItem(2);
	list1.InsertItem(3);
	list1.InsertItem(2);
	list1.InsertItem(4);

	list1.ResetList();
	int item;

	list1.DeleteItem_b(2);

	for (int i = 0; i < 3;i++)
	{
		list1.GetNextItem(item);
		cout << item << " ";
	}
	return 0;
}

template<class ItemType>
void MergeLists(UnsortedType<ItemType>& list1, UnsortedType<ItemType>& list2, UnsortedType<ItemType>& result)
{
	list1.ResetList();
	list2.ResetList();

	for (int i = 0; i < list1.LengthIs();i++)
	{
		ItemType item;
		list1.GetNextItem(item);
		result.InsertItem(item);
	}

	for (int i = 0; i < list2.LengthIs();i++)
	{
		ItemType item;
		list2.GetNextItem(item);
		result.InsertItem(item);
	}
}
