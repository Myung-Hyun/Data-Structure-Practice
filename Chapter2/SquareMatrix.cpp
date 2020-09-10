#include "SquareMatrix.h"

using namespace std;

void SquareMatrix::MakeEmpty(int n)
{
	int i, j = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			matrix[i][j] = 0;
}
void SquareMatrix::StoreValue(int i, int j, int value)
{
	matrix[i][j] = value;

}
SquareMatrix SquareMatrix::Add(SquareMatrix& A, SquareMatrix& B)
{
	SquareMatrix C;
	for (int i = 0; i < 50; i++)
		for (int j = 0; j < 50;j++)
			C.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
	return C;
}
SquareMatrix SquareMatrix::Substract(SquareMatrix& A, SquareMatrix& B)
{
	SquareMatrix C;
	for (int i = 0; i < 50; i++)
		for (int j = 0; j < 50;j++)
			C.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
	return C;
}
SquareMatrix SquareMatrix::Copy(SquareMatrix& A)
{
	SquareMatrix C;
	for (int i = 0; i < 50; i++)
		for (int j = 0; j < 50;j++)
			C.matrix[i][j] = A.matrix[i][j];
	return C;
}