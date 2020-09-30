// File: StackType.cpp
#include <iostream>
#include "StackType.h"

StackType::StackType()
{
  top = -1;
}

bool StackType::IsEmpty() const
{
  return (top == -1);
}

bool StackType::IsFull() const
{
  return (top ==  MAX_ITEMS-1);
}

void StackType::Push(ItemType newItem)
{
  if( IsFull() )
    throw FullStack();
  top++;
  items[top] = newItem;
}

void StackType::Pop()
{
  if( IsEmpty() )
    throw EmptyStack();
  top--;
}

ItemType StackType::Top()
{
  if (IsEmpty())
    throw EmptyStack();
  return items[top];
}    

void StackType::ReplaceItem(int oldItem, int newItem)
{
	for(int i=(this->top);i>-1;i--)
	{
		if (items[i]==oldItem )
			items[i]= newItem;
	}
}


