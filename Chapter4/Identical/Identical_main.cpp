#include <iostream>
#include "StackType.h"

using namespace std;

ItemType Top(StackType& stack);
bool Identical(StackType stack1, StackType stack2);

int main()
{
	StackType stack1, stack2;


	for (int i = 0; i < 3; i++)
	{
		stack1.Push(i);
		stack2.Push(i);
	}

	//cout << Identical(stack1, stack2);
	cout << stack1.Identical(stack2);


	return 0;
}

ItemType Top(StackType& stack)
{
	ItemType temp;
	temp = stack.Pop();
	stack.Push(temp);

	return temp;

}

bool Identical(StackType stack1, StackType stack2) //stack은 동적할당 변수 없으므로 복사생성자 default로 써도 문제 없다.
{
	StackType tempSt1, tempSt2; //임시 스택
	ItemType temp1, temp2;
	bool equal;
	int count = 0;
	bool flag=true;
	
	while (!stack1.IsEmpty()) //stack 크기에 접근할 수 없으므로, 일단 하나가 empty일때까지 비교한다.
	{
		temp1=stack1.Pop();
		tempSt1.Push(temp1);
		temp2 = stack2.Pop();
		tempSt2.Push(temp2);

		if (temp1 != temp2)
		{
			equal = false; 
			flag = false;
		}
		count++; //복원하기 위한 변수
	}

	//stack은 복원하기위해 empty날때까지 pop할 필요 없다. pop한대까지 임시 stack에 저장했다가 복원하면 순서 맞음.

	if (stack2.IsEmpty() && flag!=false) //위쪽에서 false가 나오면 이 if문 실행하면 안 된다.
	{
		equal = true;
	}
	else
	{
		equal = false;
	}

	for (int i = 0; i < count; i++) //stack 복원
	{
		temp1 = tempSt1.Pop();
		stack1.Push(temp1);
		temp2 = tempSt2.Pop();
		stack2.Push(temp2);
	}

	return equal;
}
