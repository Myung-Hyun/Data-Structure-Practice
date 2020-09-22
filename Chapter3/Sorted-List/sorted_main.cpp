#include <iostream>
#include "sorted.h"

using namespace std;


void MergeList(SortedType list1, SortedType list2, SortedType& result) //클라이언트 함수, 클래스 멤버를 사용하는 외부 전역함수. main보다 위에 써야 한다.
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


int main()
{
	SortedType s_list1, s_list2, s_list3; // 리스트 선언
	ItemType item1, item2, item3, item4, item5;  
	item1.Initialize(1); 
	item2.Initialize(2);
	item3.Initialize(3);
	item4.Initialize(4);
	item5.Initialize(5);
	s_list1.InsertItem(item1);  //리스트에 값을 넣는다.
	s_list1.InsertItem(item2);
	s_list2.InsertItem(item3);
	s_list2.InsertItem(item4);
	s_list2.InsertItem(item5);

	MergeList(s_list1, s_list2, s_list3);
	s_list3.Pirnt();


	return 0;
}


