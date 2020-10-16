#include <iostream>
#include "UnsortedType.h"

using namespace std;

template<class ItemType>
void MergeLists(UnsortedType<ItemType>& list1, UnsortedType<ItemType>& list2, UnsortedType<ItemType>& result);

int main()
{
	UnsortedType<int> list1;
	UnsortedType<int> list2;
	UnsortedType<int> list3;

	list1.InsertItem(2);
	list1.InsertItem(5);
	list1.InsertItem(3);

	list2.InsertItem(1);
	list2.InsertItem(9);
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
