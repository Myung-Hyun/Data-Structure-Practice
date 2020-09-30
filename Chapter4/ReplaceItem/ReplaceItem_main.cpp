#include <iostream>
#include "StackType.h"

using namespace std;

void ReplaceItem(StackType& st, int oldItem, int newItem);

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

	ReplaceItem(stack,3,5);
	
	while (!stack.IsEmpty())	//스택 내용 출력
	{
		int item = stack.Top();
		stack.Pop();
		cout << "Item : " << item << endl;
	}
	return 0;
}


void ReplaceItem(StackType& st, int oldItem, int newItem)
{
	//Exercise에서 행했던 것처럼, 또 다른 stack을 정의하여 st의 item을 top, pop을 통해 꺼내면서, 값을 비교. oldItem과 일치하는 값을 newItem으로 다른 stack에 저장합니다.
	//다음 임시로 생성했던 stack에서 아이템을 top, pop을 통해 꺼내면서 st에 다시 집어 넣습니다.
	StackType temp;

	while (!st.IsEmpty())
	{
		if (st.Top() == oldItem)
		{
			temp.Push(newItem);
			st.Pop();
		}
		else
		{
			temp.Push(st.Top());
			st.Pop();
		}
	}

	while (!temp.IsEmpty())
	{
		st.Push(temp.Top());
		temp.Pop();
	}
}
