#include "CountedQueType.h"

CountedQueType::CountedQueType(int max)
// Parameterized class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = max + 1;
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new ItemType[maxQue];
  length = 0;
}
CountedQueType::CountedQueType() :QueType()        // Default class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  length = 0;
}


CountedQueType::~CountedQueType()         // Class destructor
{
  delete [] items;
}

void CountedQueType::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
  front = maxQue - 1;
  rear = maxQue - 1;
  length = 0;
}

bool CountedQueType::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
  return (length==0);
}

bool CountedQueType::IsFull() const
// Returns true if the queue is full; false otherwise.
{
  return (length==maxQue);
}

void CountedQueType::Enqueue(ItemType newItem)
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.  
{
  if (IsFull())
    throw FullQueue();
  else
  {
      length++;
      QueType::Enqueue(newItem);
  }
}

void CountedQueType::Dequeue(ItemType& item)
// Post: If (queue is not empty) the front of the queue has been 
//       removed and a copy returned in item; 
//       othersiwe a EmptyQueue exception has been thrown.
{
  if (IsEmpty())
    throw EmptyQueue();
  else
  {
      length--;
      QueType::Dequeue(item);
  }
}


int CountedQueType::Length()
{
    return length;
}