#include <iostream>
#include "matrix.h"
using namespace std;

int main()
{
	Matrix A(1, 2, 3, 4);
	Matrix B(5, 6, 7, 8);

	Matrix resultAdd = A + B;
	Matrix resultSubstract = A - B;

	cout << resultAdd;
	cout << resultSubstract;

	return 0;
}
