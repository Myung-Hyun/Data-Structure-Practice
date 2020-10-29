// Implementation file for StackType.h

#include <cstddef>
#include <new>
#include "StackType.h"
void StackType::Push(ItemType newItem)
// Adds newItem to the top of the stack.
// Pre:  Stack has been initialized.
// Post: If stack is full, FullStack exception is thrown;
//       else newItem is at the top of the stack.

{
  if (IsFull())
    throw FullStack();
  else
  {
    NodeType* location;
    location = new NodeType;
    location->info = newItem;
    location->next = topPtr;
    topPtr = location;
  }
}
void StackType::Pop()
// Removes top item from Stack and returns it in item.
// Pre:  Stack has been initialized.
// Post: If stack is empty, EmptyStack exception is thrown;
//       else top element has been removed.
{
  if (IsEmpty())
    throw EmptyStack();
  else
  {  
    NodeType* tempPtr;
    tempPtr = topPtr;
    topPtr = topPtr->next;
    delete tempPtr;
  }
}
ItemType StackType::Top()
// Returns a copy of the top item in the stack.
// Pre:  Stack has been initialized.
// Post: If stack is empty, EmptyStack exception is thrown;
//       else a copy of the top element is returned.
{
  if (IsEmpty())
    throw EmptyStack();
  else
    return topPtr->info;  
}
bool StackType::IsEmpty() const
// Returns true if there are no elements on the stack; false otherwise.
{
    return (topPtr == NULL);
}
bool StackType::IsFull() const
// Returns true if there is no room for another ItemType 
//  on the free store; false otherwise.
{
  NodeType* location;
  try
  {
    location = new NodeType;
    delete location;
    return false;
  }
  catch(std::bad_alloc)
  {
    return true;
  }
}

StackType::~StackType()
// Post: stack is empty; all items have been deallocated.
{
    NodeType* tempPtr;

    while (topPtr != NULL)
    {
        tempPtr = topPtr;
        topPtr = topPtr->next;
        delete tempPtr;
    }
}

StackType::StackType()	// Class constructor.
{
    topPtr = NULL;
}

void StackType::Copy(StackType& anotherStack)
{
    //anotherStack.topPtr = topPtr;
    NodeType* location;
    location = topPtr;

    //처음 한번은 tempPtr의 주소를 기억했다가 topPtr로 가리키기 위해 따로 빼준다.
    NodeType* tempPtr;
    tempPtr = new NodeType;
    tempPtr->info = location->info;
    tempPtr->next = NULL;
    anotherStack.topPtr = tempPtr;
    location = location->next;

    //그러면 location이 top쪽에서 움직이면서 copy할 수 있다. 
    while (location!=NULL)
    {
        NodeType* tempPtr;
        tempPtr = new NodeType;
        tempPtr->info = location->info;
        tempPtr->next = NULL;
        location = location->next;
    }
}

