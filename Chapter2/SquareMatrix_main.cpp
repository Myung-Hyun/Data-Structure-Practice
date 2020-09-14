#include <iostream>
#include "SquareMatrix.h"

using namespace std;

//test driver: �ϼ��� ���, ������Ʈ�� �ӽ÷� ȣ���ϴ� SW
int main()
{
	SquareMatrix A;
	A.MakeEmpty(10);

	SquareMatrix B;
	B.MakeEmpty(10);

	A.StoreValue(1, 1, 1);
	B.StoreValue(1, 1, 2);
	cout << "A" <<endl;
	A.print();
	cout << "B" <<endl;
	B.print();

	SquareMatrix C;
	C=A.Add(B);
	cout << "A+B"<<endl;
	C.print();

	C = A.Substract(B);
	cout << "A-B"<<endl;
	C.print();

	C = A.Copy();
	cout << "A copy to C"<<endl;
	C.print();

	return 0;
}