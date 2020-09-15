#include <iostream>
#include <fstream>
#include "MatrixType.h"


using namespace std;
enum Operation{ADD, SUB, MUL};

int main()
{
	MatrixType A, B, C;
	ofstream out;
	out.open("matrix_result");

	if (!out)
	{
		cout << "Cannot open file";
		return 1;
	}

	Operation op=ADD; //열거형 변수 switch문에 활용하는 방법. 
	switch (op)
	{
	case ADD:
		A.SetSize(2, 3);
		B.SetSize(2, 3);
		C.SetSize(2, 3);
		cout << A.AddSubCompatible(B) << endl; //true
		
		if (A.AddSubCompatible(B) != 1)
		{
			exit(100);
		}

		A.StoreItem(1, 1, 2);
		B.StoreItem(2, 2, 3);
		A.Add(B, C);
		C.Print(out); //A+B 결과 matrix_result에 출력
		//C.Print_console();
		C.MakeEmpty();
		break;
	case SUB:
		A.SetSize(2, 3);
		B.SetSize(2, 3);
		C.SetSize(2, 3);
		cout << A.AddSubCompatible(B) << endl; //true

		if (A.AddSubCompatible(B) != 1)
		{
			exit(100);
		}

		A.StoreItem(1, 1, 2);
		B.StoreItem(2, 2, 3);
		A.Sub(B, C);
		C.Print(out); //A-B 결과 matrix_result에 출력
		C.MakeEmpty();
		break;

	case MUL:
		A.SetSize(2, 3);
		B.SetSize(3, 2);
		C.SetSize(2, 2);
		cout << A.MultCompatible(B) << endl; //ture

		if (A.MultCompatible(B) != 1)
		{
			exit(100);
		}

		A.StoreItem(1, 1, 2);
		B.StoreItem(2, 2, 1);
		A.Mult(B, C);
		C.Print(out); //A*B 결과 matrix_result에 출력
		C.MakeEmpty();
		break;
	default:
		break;
	}

	
	

	out.close();
	return 0;
}
