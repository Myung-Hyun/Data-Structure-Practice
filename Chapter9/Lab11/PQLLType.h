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



//����Ʈ�� �������� �߰��մϴ�.
template<class ItemType>
void PQLLType<ItemType>::Enqueue(ItemType newItem)
{
	if (linkedlist.IsFull())
		throw FullPQLL();
	else
	{
		length++;
		linkedlist.InsertItem(newItem); // ������ �߰�
	}
}


//����Ʈ�� ���� �տ� �ִ� �������� ��������, 
//�ش� �������� �����մϴ�.
template<class ItemType>
void PQLLType<ItemType>::Dequeue(ItemType& item)
{
	if (length == 0)
		throw EmptyPQLL();
	else {
		linkedlist.ResetList(); // iterator�� ����� �غ�
		linkedlist.GetNextItem(item); //����Ʈ���� �������� ���
		linkedlist.DeleteItem(item); //�ش� ������ ����			
		length--;
	}
}

