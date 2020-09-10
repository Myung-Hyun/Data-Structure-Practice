#pragma once
#include <fstream>
#include <iostream>
using namespace std;

class Matrix
{
	
public:
	Matrix(int a, int b, int c, int d)
	{
		matrix[0][0] = a;
		matrix[0][1] = b;
		matrix[1][0] = c;
		matrix[1][1] = d;
	}

	Matrix operator +(Matrix B)
	{
		Matrix C(0,0,0,0);
		C.matrix[0][0] = this->matrix[0][0] + B.matrix[0][0];
		C.matrix[0][1] = this->matrix[0][1] + B.matrix[0][1];
		C.matrix[1][0] = this->matrix[1][0] + B.matrix[1][0];
		C.matrix[1][1] = this->matrix[1][1] + B.matrix[1][1];
		return C;
	}
	Matrix operator -(Matrix B)
	{
		Matrix C(0, 0, 0, 0);
		C.matrix[0][0] = this->matrix[0][0] - B.matrix[0][0];
		C.matrix[0][1] = this->matrix[0][1] - B.matrix[0][1];
		C.matrix[1][0] = this->matrix[1][0] - B.matrix[1][0];
		C.matrix[1][1] = this->matrix[1][1] - B.matrix[1][1];
		return C;
	}
	friend ostream& operator<<(ostream& out, const Matrix& A)
	{
		out << A.matrix[0][0] << " " << A.matrix[0][1] << endl;
		out << A.matrix[1][0] << " " << A.matrix[1][1] << endl;
		return out;

	}

private:
	int matrix[2][2];


};