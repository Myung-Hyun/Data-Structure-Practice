#include "QueType.h"

QueType::QueType(int max)
// Parameterized class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
    // To-Do 2: 기본생성자를 참고하여 생성자 작성
    maxQue = max;
    front = maxQue;
    rear = maxQue;
    items = new ItemType[maxQue];
    length = 0;
}
QueType::QueType()          // Default class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = 50;
  front = maxQue;
  rear = maxQue;
  items = new ItemType[maxQue];
  length = 0;
}
QueType::~QueType()         // Class destructor
{
  delete [] items;
}

void QueType::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
  front = maxQue;
  rear = maxQue;
}

bool QueType::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
	return (length == 0);
}

bool QueType::IsFull() const
// Returns true if the queue is full; false otherwise.
{
  return (length == maxQue);
}

void QueType::Enqueue(ItemType newItem)
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.  
{
  if (IsFull())
    throw FullQueue();
  else
  {
    rear = (rear) % maxQue;
    items[rear] = newItem;
	rear += 1;
	length++;
  }
}

void QueType::Dequeue(ItemType& item)
// Post: If (queue is not empty) the front of the queue has been 
//       removed and a copy returned in item; 
//       othersiwe a EmptyQueue exception has been thrown.
{
  if (IsEmpty())
    throw EmptyQueue();
  else
  {
	front = (front) % maxQue;
    item = items[front];
	front = front + 1;
	length--;
  }
}
