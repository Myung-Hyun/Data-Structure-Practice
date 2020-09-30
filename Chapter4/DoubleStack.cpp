#include <iostream>
#include "DoubleStack.h"

using namespace std;


doublestack::doublestack()
{
	top_small = -1;
	top_big = 200;
}

void doublestack::Push(int item)
{
	if (this->IsFull() == true)
	{
		cout << "Stack is already full ";
	}
	else
	{
		if (item <= 1000 )
		{
			top_small++;
			items[top_small] = item;
		}
		else
		{
			top_big--;
			items[top_big] = item;
		}
	}

}

void doublestack::Print()
{
	while (top_small != -1)
	{
		cout << items[top_small] << endl;
		top_small--;
	}

	while (top_big != 200)
	{
		cout << items[top_big] << endl;
		top_big++;
	}
}

bool doublestack::IsFull()
{
	if (this->top_big == (this->top_small)+1) //두 flag가 연속이면 1 차이난다.
		return true;
	else
		return false;
}