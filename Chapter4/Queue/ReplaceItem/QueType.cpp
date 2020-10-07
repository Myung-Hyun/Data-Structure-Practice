#include "QueType.h"

QueType::QueType(int max)
// Parameterized class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = max + 1;
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new ItemType[maxQue];
}
QueType::QueType()          // Default class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
  maxQue = 501;
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new ItemType[maxQue];
}
QueType::~QueType()         // Class destructor
{
  delete [] items;
}

void QueType::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
  front = maxQue - 1;
  rear = maxQue - 1;
}

bool QueType::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
  return (rear == front);
}

bool QueType::IsFull() const
// Returns true if the queue is full; false otherwise.
{
  return ((rear + 1) % maxQue == front);
}

void QueType::Enqueue(ItemType newItem)
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.  
{
  if (IsFull())
    throw FullQueue();
  else
  {
    rear = (rear +1) % maxQue;
    items[rear] = newItem;
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
    front = (front + 1) % maxQue;
    item = items[front];
  }
}

void QueType::ReplaceItem(ItemType oldItem, ItemType newItem)
{
    int length = 0;

    if (rear >= front)
    {
        length = rear - front;
    }
    else
    {
        length = rear - front + maxQue;
    }

    for (int i = 0; i < length; i++)
    {
        if (items[i] == oldItem)
        {
            items[i] = newItem;
        }
    }

}

bool QueType::Identical(QueType& queue)
{
    int length = 0;
    int length2 = 0;
    bool equal;

    if (rear >= front)
    {
        length = rear - front;
    }
    else
    {
        length = rear - front + maxQue;
    }

    if (queue.rear >= queue.front)
    {
        length2 = queue.rear - queue.front;
    }
    else
    {
        length2 = queue.rear - queue.front + queue.maxQue;
    }

    if (length != length2)
    {
        equal = false;
        return equal;
    }

    for (int i = 0; i < length; i++)
    {
        if (this->items[i] != queue.items[i])
        {
            equal = false;
            return equal;
        }
    }
    equal = true;
    return equal;
}