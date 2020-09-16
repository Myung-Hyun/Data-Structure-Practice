// Implementation file for Unsorted.h

#include "unsorted.h"
#include <iostream>

using namespace std;

UnsortedType::UnsortedType()
{
  length = 0;
  currentPos = 0; 
}
bool UnsortedType::IsFull() const
{
  return (length == MAX_ITEMS);
}

int UnsortedType::LengthIs() const
{
  return length;
}
void UnsortedType::RetrieveItem(ItemType& item, bool& found) 
// Pre:  Key member(s) of item is initialized. 
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been stored in item; 
//       otherwise, item is unchanged. 
{
  bool moreToSearch;
  int location = 0;
  found = false;

  moreToSearch = (location < length);

  while (moreToSearch && !found) 
  {
    switch (item.ComparedTo(info[location]))
    {
      case LESS    : 
      case GREATER : location++;
                     moreToSearch = (location < length);
                     break;
      case EQUAL   : found = true;
                     item = info[location];
                     break;
    }
  }
}
void UnsortedType::InsertItem(ItemType item)
// Post: item is in the list.
{
  info[length] = item;
  length++;
}
void UnsortedType::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
  int location = 0;

  while (item.ComparedTo(info[location]) != EQUAL) //������ ��� ������ ������� �ʴ� �޸𸮿� �����ϰ� �ȴ�. (���� �߻�)
    location++;

  info[location] = info[length - 1];
  length--;
}

void UnsortedType::DeleteItem_a(ItemType item)
{
	bool deleted = false; //flag�� ���� �ݺ��� ������ �߰��� �� �ִ�. 
	for (int i = 0; i < length && !deleted; i++) //�˻�Ƚ�� �����ϸ�, flag�� ���� �����ϸ� for���� ���� �ʰ��Ѵ�. �� ���� �� ��� ������ �״�� �д�.
	{
		if (item.ComparedTo(info[i]) == EQUAL) {
			info[i] = info[length - 1];
			deleted = true;
		}
	}
	length--;
}

void UnsortedType::DeleteItem_c(ItemType item)
{
	int I = 0;
	while (I < length)
	{
		if (item.ComparedTo(info[I]) == EQUAL) {
			info[I] = info[length - 1]; //length�� ���̱� ������ ��� list�� �� ��Ҹ� �������� �ȴ�.
			// ���� �� ���� i ��ġ�� ���� ����Ǿ����Ƿ� ���߿� �ٽ� Ȯ�� �ϵ��� i �� ���� ���� ����(length-1 ��Ұ� ������ ����� �� ����)
			length--;
		}
		else {
			I++;
		}
	}
}

void UnsortedType::ResetList()
// Post: currentPos has been initialized.
{
  currentPos = -1;
}

void UnsortedType::GetNextItem(ItemType& item)
// Post: item is current item.
//       Current position has been updated.
{
  currentPos++;
  item = info[currentPos];
}

int UnsortedType::ListSum(int K)
{

	ItemType zero;
	ItemType sum; //0���� �ʱ�ȭ
	int* N = new int[K+1];
	ItemType* n=new ItemType[K+1]; //�����Ҵ��� �����ͺ��� �ʱ�ȭ�ϴ� �ǹ�?

	//�� �Է�
	for (int i=0;i < K;i++)
	{
		cin >> N[i]; //cin���� �ԷµǴ� ���� �����̹Ƿ�, ������ �Է¹ް� 
		n[i].Initialize(N[i]); //ItemType���� �ٲ� �ش�.
		if (n[i].ComparedTo(zero)!=EQUAL)
		{
			info[length] = n[i];
			length++;
		}
		else
		{
			length--;
		}
	}

	//List �� ���
	for (int i=0; i < length;i++)
	{
		sum=sum+info[i];
	}
	delete[] N;
	delete[] n;
	return sum.Value();
}