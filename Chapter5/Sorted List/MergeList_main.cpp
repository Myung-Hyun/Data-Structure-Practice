#include <iostream>
#include "SortedType.h"

using namespace std;

template<class ItemType>
void MergeLists(SortedType<ItemType>& list1, SortedType<ItemType>& list2, SortedType<ItemType>& result);

int main()
{
	SortedType<int> list1;
	SortedType<int> list2;
	SortedType<int> list3;

	list1.InsertItem(1);
	list1.InsertItem(3);
	list1.InsertItem(5);

	list2.InsertItem(2);
	list2.InsertItem(4);
	list2.InsertItem(6);

	list1.MergeLists(list2, list3);
	//MergeLists(list1, list2, list3);

	list3.ResetList();
	int item;
	
	
	for (int i = 0; i < 6;i++)
	{
		list3.GetNextItem(item);
		cout << item << " ";
	}
	

	return 0;
}

template<class ItemType>
void MergeLists(SortedType<ItemType>& list1, SortedType<ItemType>& list2, SortedType<ItemType>& result)
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
