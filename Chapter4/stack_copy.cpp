#include <iostream>
#include "StackTType.h"


using namespace std;

StackType<int> Stack_Copy(StackType<int>);

int main()
{
	StackType<int> A;
	StackType<int> B;
	A.Push(9); // 1�� ���ÿ� �ִ´�.
	A.Push(8);
	A.Push(4);
	A.Push(7);
	A.Push(5);
	A.Push(3);
	B = Stack_Copy(A);

	return 0;
}

StackType<int> Stack_Copy(StackType<int> A) //������ �����͸� �������� �ʱ� ���� pass by value
{
	StackType<int> C; //�ӽ�
	StackType<int> B;
	
	while (!A.IsEmpty()) //stack�� ũ�⸦ �� �� �ִ� ��� �Լ� ���� ������. 
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