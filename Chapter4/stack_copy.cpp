#include <iostream>
#include "StackTType.h"


using namespace std;

StackType<int> Stack_Copy(StackType<int>);

int main()
{
	StackType<int> A;
	StackType<int> B;
	A.Push(9); // 1을 스택에 넣는다.
	A.Push(8);
	A.Push(4);
	A.Push(7);
	A.Push(5);
	A.Push(3);
	B = Stack_Copy(A);

	return 0;
}

StackType<int> Stack_Copy(StackType<int> A) //스택의 데이터를 변경하지 않기 위해 pass by value
{
	StackType<int> C; //임시
	StackType<int> B;
	
	while (!A.IsEmpty()) //stack의 크기를 알 수 있는 멤버 함수 없기 때문에. 
	{
		//cout << A.Top() << endl;
		C.Push(A.Top());
		A.Pop();
	}

	while (!C.IsEmpty())  
	{
		//cout << C.Top() << endl;
		B.Push(C.Top());
		C.Pop();
	}
	return B;
}