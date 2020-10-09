#include <iostream>
#include "QueType.h"
using namespace std;

int Length(QueType& queue);


int main()
{
	QueType queue;
	int length = 0;

	for (int i = 0; i < 5; i++)
	{
		queue.Enqueue(i);
	}

	//length= queue.Length();
	length = Length(queue);

	cout << length;



	return 0;
}

int Length(QueType& queue)
{
	int length=0;
	ItemType temp=0;
	QueType tempQue;

	while (!queue.IsEmpty())
	{
		queue.Dequeue(temp);
		tempQue.Enqueue(temp);
		length++;
	}

	while (!tempQue.IsEmpty()) //queue º¹¿ø
	{
		tempQue.Dequeue(temp);
		queue.Enqueue(temp);
	}


	return length;
}