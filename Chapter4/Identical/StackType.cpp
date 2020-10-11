// File: StackType.cpp

#include "StackType.h"
#include <iostream>
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

ItemType StackType::Pop()
{
  if( IsEmpty() )
    throw EmptyStack();

  int temp=top;
  top--;
  return items[temp];
}

ItemType StackType::Top()
{
  if (IsEmpty())
    throw EmptyStack();
  return items[top];
}    

bool StackType::Identical(StackType& stack)
{
    if (top != stack.top)
    {
        return false;
    }

    for (int i = 0; i < top+1; i++)
    {
        if (items[i] != stack.items[i])
            return false;
    }

    return true;
}


