#include <iostream>

#include "QueType.h"
using namespace std;

void ReplaceItem(QueType& queue, int oldItem, int newItem);

int main()
{
	QueType queue;

	for (int i = 0; i < 10; i++)
	{
		ItemType item = i;
		cout << item << " ";
		queue.Enqueue(item);
	}

	cout << endl;

	//queue.ReplaceItem(3, 2);
	ReplaceItem(queue, 3, 2);

	for (int i = 0; i < 10; i++)
	{
		ItemType item = 0;
		queue.Dequeue(item);
		cout << item << " ";
	}



	return 0;
}

void ReplaceItem(QueType& queue, int oldItem, int newItem)
{
	QueType temp;
	ItemType tempItem;

	while (!queue.IsEmpty())
	{
		queue.Dequeue(tempItem);
		if (oldItem==tempItem)
			temp.Enqueue(newItem);
		else
			temp.Enqueue(tempItem);
	}

	while (!temp.IsEmpty())
	{
		temp.Dequeue(tempItem);
		queue.Enqueue(tempItem);
	}

}