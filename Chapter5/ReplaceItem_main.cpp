#include <iostream>
#include "StackType.h"

using namespace std;

void ReplaceItem(StackType& stack, ItemType oldItem, ItemType newItem);



int main()
{
	StackType stack;
	stack.Push(8);
	stack.Push(3);
	stack.Push(9);
	stack.Push(8);
	stack.Push(3);
	stack.Push(7);
	stack.Push(5);
	stack.Push(3);

	//ReplaceItem(stack, 3, 5);
	stack.ReplaceItem(3, 5);

	while (!stack.IsEmpty())	//스택 내용 출력
	{
		int item = stack.Top();
		stack.Pop();
		cout << "Item : " << item << endl;
	}

	return 0;
}


void ReplaceItem(StackType& stack, ItemType oldItem, ItemType newItem)
{
	StackType temp;

	while (!stack.IsEmpty())
	{
		if (stack.Top() == oldItem)
		{
			temp.Push(newItem);
			stack.Pop();
		}
		else
		{
			temp.Push(stack.Top());
			stack.Pop();
		}
	}

	while (!temp.IsEmpty())
	{
		stack.Push(temp.Top());
		temp.Pop();
	}

}
