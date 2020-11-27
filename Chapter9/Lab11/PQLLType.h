#pragma once
#include "SortedType.h"

template<class ItemType>
class PQLLType
{
public:
	PQLLType();
	~PQLLType();
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	void Enqueue(ItemType newItem);
	void Dequeue(ItemType& item);
	void Print();
private:
	int length;
	SortedType<ItemType> linkedlist;
	//int maxItems;
};

template<class ItemType>
bool PQLLType<ItemType>::IsFull() const
{
	if (linkedlist.IsFull())
	{
		return true;
	}
	else
	{
		return false;
	}
}



//리스트에 아이템을 추가합니다.
template<class ItemType>
void PQLLType<ItemType>::Enqueue(ItemType newItem)
{
	if (linkedlist.IsFull())
		throw FullPQLL();
	else
	{
		length++;
		linkedlist.InsertItem(newItem); // 아이템 추가
	}
}


//리스트의 가장 앞에 있는 아이템을 가져오고, 
//해당 아이템을 삭제합니다.
template<class ItemType>
void PQLLType<ItemType>::Dequeue(ItemType& item)
{
	if (length == 0)
		throw EmptyPQLL();
	else {
		linkedlist.ResetList(); // iterator를 사용할 준비
		linkedlist.GetNextItem(item); //리스트에서 아이템을 얻고
		linkedlist.DeleteItem(item); //해당 아이템 삭제			
		length--;
	}
}

