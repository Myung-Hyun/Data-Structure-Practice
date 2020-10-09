#include "QueType.h"
#include <iostream>

using namespace std;

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
  minimum_pos = 0;
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
  minimum_pos = 0;
}

QueType::QueType(QueType& queue)
{
    maxQue = queue.maxQue;
    front = queue.front;
    rear = queue.rear;
    items = new ItemType[maxQue];
    minimum_pos = queue.minimum_pos;

    for (int i = 0; i < maxQue; i++)
    {
        items[i] = queue.items[i];
    }

    /*if (rear < front)
    {
        for (int i = 0; i <=rear; i++)
        {
            this->items[i] = queue.items[i];
        }
        for (int i = front + 1; i < maxQue;i++)
        {
            this->items[i] = queue.items[i];
        }
    }
    else
    {
        for (int i = (front+1)%maxQue; i <= rear; i++)
        {
            this->items[i] = queue.items[i];
        }
    }*/
   
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

void QueType::MinEnqueue(ItemType newItem)
{
    int length = this->Length();
    for (int i = (front + 1) % maxQue; i < (front + 1) % maxQue + length; i++)
    {
        if (items[i] == -1)
        {
            items[i] = newItem;
            break;
        }
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

void QueType::MinDequeue(ItemType& item)
{
    ItemType minimum=0;//초기화는 -1이 아닌 처음 값으로 해야한다. 
    int minindex = 0;
    int length = this->Length(); //요소가 없어져도 length가 유지되어야 한다. 

    
    for (int i = (front + 1) % maxQue; i < (front + 1) % maxQue + length; i++) //i를 증가시키면서 items[i]가 -1이 아닌 값을 찾다가 처음 찾으면 초기화하고 break
    {
        if (items[i] != -1)
        {
            minimum = items[i];
            break;
        }
    }

    for (int i = (front + 1) % maxQue; i < (front + 1) % maxQue + length; i++) //요소가 -1인 경우는 제외하고, minimum_pos 찾는다.
    {
        
        if (items[i] <= minimum && items[i]!=-1) //등호 빠지면 초기화된 minimum이 가장 작을 때 조건을 만족하지 못한다. 즉, 제일 처음 값이 제일 작아진 순간부터 제대로 작동안함.
        {
            minimum = items[i];
            minimum_pos = i;
        }
    }
    
    item = minimum;
    //cout << minimum_pos << ": pos" << endl;
    items[minimum_pos] = -1; //minimup_pos 위치에 -1 대입해준다.
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

    for (int i = (front + 1) % maxQue; i < (front + 1) % maxQue + length; i++)
    {
        if (items[i] == oldItem)
        {
            items[i] = newItem;
        }
    }

}

bool QueType::Identical(QueType queue)
{
    int length = 0;
    int length2 = 0;
    bool equal;

    // 두 queue의 길이를 계산.
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

    //길이가 같지 않으면 두 queue는 다르다.
    if (length != length2)
    {
        equal = false;
        return equal;
    }

    //길이가 같으면 다른 요소 있는지 반복하면서 확인한다. 이때 index는 요소가 있는 부분이어야 한다.
    //여기서도 rear front 대소비교해서 나눠서 구현해도 된다. 
    for (int i = (front+1)%maxQue; i < (front + 1) % maxQue+length; i++)
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


int QueType::Length()
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

    return length;

}