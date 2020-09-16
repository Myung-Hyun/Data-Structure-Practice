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

  while (item.ComparedTo(info[location]) != EQUAL) //삭제될 요소 없으면 사용하지 않는 메모리에 접근하게 된다. (에러 발생)
    location++;

  info[location] = info[length - 1];
  length--;
}

void UnsortedType::DeleteItem_a(ItemType item)
{
	bool deleted = false; //flag를 통해 반복의 조건을 추가할 수 있다. 
	for (int i = 0; i < length && !deleted; i++) //검색횟수 제한하며, flag를 통해 삭제하면 for문을 돌지 않게한다. 즉 삭제 할 요소 없으면 그대로 둔다.
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
			info[I] = info[length - 1]; //length를 줄이기 때문에 계속 list의 끝 요소를 가져오면 된다.
			// 삭제 후 현재 i 위치의 값이 변경되었으므로 나중에 다시 확인 하도록 i 값 변경 하지 않음(length-1 요소가 삭제할 요소일 수 있음)
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
	ItemType sum; //0으로 초기화
	int* N = new int[K+1];
	ItemType* n=new ItemType[K+1]; //동적할당은 포인터변수 초기화하는 의미?

	//값 입력
	for (int i=0;i < K;i++)
	{
		cin >> N[i]; //cin에서 입력되는 값은 정수이므로, 정수로 입력받고 
		n[i].Initialize(N[i]); //ItemType으로 바꿔 준다.
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

	//List 합 계산
	for (int i=0; i < length;i++)
	{
		sum=sum+info[i];
	}
	delete[] N;
	delete[] n;
	return sum.Value();
}