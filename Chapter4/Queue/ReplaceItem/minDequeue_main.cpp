#include <iostream>
#include <cstdlib> //srand(), rand()
#include <ctime>
#include "QueType.h"

using namespace std;

int main()
{
	QueType queue;
	srand((unsigned int)time(NULL));

	/*for (int i = 0; i < 10; i++)
	{
		ItemType item = rand();
		cout << item << " ";
		queue.Enqueue(item);
	}*/

	queue.Enqueue(125);
	queue.Enqueue(9);
	queue.Enqueue(11);
	queue.Enqueue(1458);
	queue.Enqueue(134);

	cout << endl;

	for (int i = 0; i < 2; i++)
	{
		ItemType item = 0;
		queue.MinDequeue(item);
		//cout << item << " ";
	}

	queue.MinEnqueue(1);
	queue.MinEnqueue(122);

	for (int i = 0; i < 5; i++)
	{
		ItemType item = 0;
		queue.Dequeue(item);
		cout << item << " ";
	}


	return 0;
}