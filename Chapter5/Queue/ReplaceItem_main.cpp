#include <iostream>

#include "QueType.h"
using namespace std;

template <class ItemType>
void ReplaceItem(QueType<ItemType>& queue, int oldItem, int newItem);

int main()
{
	QueType<int> queue;

	for (int i = 0; i < 10; i++)
	{
		int item = i;
		cout << item << " ";
		queue.Enqueue(item);
	}

	cout << endl;

	queue.ReplaceItem(3, 2);
	//ReplaceItem<int>(queue, 3, 2);

	for (int i = 0; i < 10; i++)
	{
		int item = 0;
		queue.Dequeue(item);
		cout << item << " ";
	}



	return 0;
}

template <class ItemType>
void ReplaceItem(QueType<ItemType>& queue, int oldItem, int newItem)
{
	QueType<ItemType> temp;
	ItemType tempItem;

	while (!queue.IsEmpty())
	{
		queue.Dequeue(tempItem);
		if (oldItem == tempItem)
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
