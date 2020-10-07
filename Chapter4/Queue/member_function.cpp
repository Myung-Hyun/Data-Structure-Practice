#include <iostream>
#include <cstdlib> //srand(), rand()
#include <ctime>
#include "QueType.h"

using namespace std;

int main()
{
	QueType queue;
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10; i++)
	{
		ItemType item = rand();
		cout << item << " ";
		queue.Enqueue(item);
	}

	cout << endl;

	for (int i = 0; i < 10; i++)
	{
		ItemType item=0;
		queue.Dequeue(item);
		cout << item << " ";
	}


	return 0;
}
