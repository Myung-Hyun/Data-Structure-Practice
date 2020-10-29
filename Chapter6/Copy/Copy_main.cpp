#include <iostream>
#include "StackType.h"
using namespace std;


int main()
{
	StackType stack;
	StackType stack2;

	stack.Push(3);
	stack.Push(2);
	stack.Push(1);

	stack.Copy(stack2);

	int temp;

	for (int i = 0;i < 3;i++)
	{
		temp = stack.Top();
		cout << temp;
		stack.Pop();
	}


	return 0;
}
