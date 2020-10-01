// Implementation file for sorted.h

#include "sorted.h"
#include <iostream>

using namespace std;


SortedType::SortedType()
{
  length = 0;
}
bool SortedType::IsFull() const
{
  return (length == MAX_ITEMS);
}

int SortedType::LengthIs() const
{
  return length;
}

void SortedType::RetrieveItem(ItemType& item, bool& found) 
{
  int midPoint;
  int first = 0;
  int last = length - 1;

  bool moreToSearch = first <= last;
  found = false;
   while (moreToSearch && !found) 
  {
    midPoint = ( first + last) / 2;
    switch (item.ComparedTo(info[midPoint])) 
    {
      case LESS    : last = midPoint - 1;
                     moreToSearch = first <= last;
                     break;
      case GREATER : first = midPoint + 1;
                     moreToSearch = first <= last;
                     break;
      case EQUAL   : found = true;
                     item = info[midPoint];
                     break;
    }
  }
}

void SortedType::DeleteItem(ItemType item) 
{
  int location = 0;

  while (item.ComparedTo(info[location]) != EQUAL)
    location++;
  for (int index = location + 1; index < length; index++)
    info[index - 1] = info[index];
  length--;
}

void SortedType::InsertItem(ItemType item) 
{
  bool moreToSearch;
  int location = 0;

  moreToSearch = (location < length);
  while (moreToSearch) 
  {
    switch (item.ComparedTo(info[location])) 
    {
      case LESS    : moreToSearch = false;
                     break;
      case GREATER : location++;
                     moreToSearch = (location < length);
                     break;
    } 
  } 
  for (int index = length; index > location; index--)
    info[index] = info[index - 1];
  info[location] = item;
  length++;
}

void SortedType::ResetList()
// Post: currentPos has been initialized.
{
  currentPos = -1;
}

void SortedType::GetNextItem(ItemType& item)
// Post: item is current item.
//       Current position has been updated.
{
  currentPos++;
  item = info[currentPos];
}

void SortedType::Start(string pattern) //','를 기준으로 구분.
{
	int count = 0;
	for (int i = 0; i < (*this).LengthIs(); i++) //pattern이 일치하는 단어 수를 먼저 찾아야 한다.
	{
		int index = (this->info[i]).Find_start(pattern);
		if (index != -1)
		{
			count++;

		}
	}

	if (count == 0) //일치하는 단어 수에 따라 동작을 다시 작성한다.
	{
		cout << "There is no matching pattern" <<endl;
	}
	else if (count == 1)
	{
		for (int i = 0; i < (*this).LengthIs(); i++)
		{
			int index = (this->info[i]).Find_start(pattern);
			if (index != -1)
			{
				this->info[i].Print(cout);
				cout << endl;
			}
		}
	}
	else {
		for (int i = 0; i < (*this).LengthIs(); i++)
		{

			int index = (this->info[i]).Find_start(pattern);

			if (index != -1)
			{
				(this->info[i]).Printname();
				cout << " ";
			}
		}
		cout << endl;
	}

}
void SortedType::End(string pattern) // 문자열 크기를 기준으로 뒤쪽 10개에서만 찾는다.
{
	int count = 0;
	for (int i = 0; i < (*this).LengthIs(); i++) //pattern이 일치하는 단어 수를 먼저 찾아야 한다.
	{
		int index = (this->info[i]).Find_end(pattern);
		if (index != -1)
		{
			count++;

		}
	}

	if (count == 0) //일치하는 단어 수에 따라 동작을 다시 작성한다.
	{
		cout << "There is no matching pattern"<<endl;
	}
	else if (count == 1)
	{
		for (int i = 0; i < (*this).LengthIs(); i++)
		{
			int index = (this->info[i]).Find_end(pattern);
			if (index != -1)
			{
				this->info[i].Print(cout);
				cout << endl;
			}
		}
	}
	else {
		for (int i = 0; i < (*this).LengthIs(); i++)
		{

			int index = (this->info[i]).Find_end(pattern);

			if (index != -1)
			{
				(this->info[i]).Printname();
				cout << " ";
			}
		}
		cout << endl;
	}

}

//sorted list의 각 item에 pattern이 있는지 찾는다. 
void SortedType::Contain(string pattern)
{
	int count = 0;
	for (int i=0; i < (*this).LengthIs(); i++) //pattern이 일치하는 단어 수를 먼저 찾아야 한다.
	{
		int index=(this->info[i]).Find(pattern);
		if (index != -1)
		{
			count++;
			
		}
	}
	
	if (count == 0) //일치하는 단어 수에 따라 동작을 다시 작성한다.
	{
		cout << "There is no matching pattern"<<endl;
	}
	else if (count == 1)
	{
		for (int i = 0; i < (*this).LengthIs(); i++)
		{
			int index = (this->info[i]).Find(pattern);
			if (index != -1)
			{
				this->info[i].Print(cout);
				cout << endl;
			}
		}
	}
	else {
		for (int i = 0; i < (*this).LengthIs(); i++)
		{
			
			int index = (this->info[i]).Find(pattern);
			
			if (index != -1)
			{						
				(this->info[i]).Printname();
				cout << " ";
			}
		}
		cout << endl;
	}
	
}

