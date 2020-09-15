#include <iostream>
#include "MatrixType.h"


MatrixType::MatrixType()
//pre: 2차원 matrix는 초기화 되어야한다. 
//post: matrix가 0으로 채워진다.
{
	for (int i = 0;i < 10;i++)
	{
		for (int j = 0;j < 10;j++)
		{
			this->values[i][j] = 0; //초기화하지 않고 사용하는 경우 -858993460 이런 값 뜬다.
		}
	}
	numRows = 0;
	numCols = 0;
}

void MatrixType::MakeEmpty()
//pre: 임의의 matrix에 대해서
//post: 모든 원소를 0으로 만든다.
{
	for (int i = 0;i < 10;i++)
		for (int j = 0;j < 10;j++)
			this->values[i][j] = 0;

}
void MatrixType::SetSize(int rowsSize, int colSize)
//pre: rowsSize, colSize는 10이내의 수이다.
//post: 행과 열의 크기를 정해준다. 행렬 객체 생성 후에 항상 이 함수를 이용해서 크기 정해주어야 한다.
{
	numRows = rowsSize;
	numCols = colSize;
}
void MatrixType::StoreItem(int item, int row, int col)
//pre: 원하는 값과 위치(행,렬)을 받는다.
//post: 값을 원하는 위치에 저장한다.
{
	values[row-1][col-1] = item; //index는 1 작다.
}
void MatrixType::Add(MatrixType otherOperand, MatrixType& result)
//pre: 두 행렬을 더해야 한다.
//post: 두 행렬을 더한 결과를 result에 저장한다. 
{
	for (int i = 0;i < this->numRows;i++)
		for (int j = 0;j < this->numCols;j++) {
			result.values[i][j] = this->values[i][j] + otherOperand.values[i][j];
		}
}
void MatrixType::Sub(MatrixType otherOperand, MatrixType& result)
//pre: 두 행렬을 빼야 한다.
//post: 두 행렬을 뺀 결과를 result에 저장한다. 
{
	for (int i = 0;i < this->numRows;i++)
		for (int j = 0;j < this->numCols;j++)
			result.values[i][j] = this->values[i][j] - otherOperand.values[i][j];
}
void MatrixType::Mult(MatrixType otherOperand, MatrixType& result)
//pre: 두 행렬을 곱해야 한다.
//post: 두 행렬을 곱한 결과를 result에 저장한다. 
{
	for (int i = 0;i < this->numRows;i++)
		for (int j = 0;j < otherOperand.numCols;j++)
		{
			int sum=0;
			for (int k = 0; k < this->numCols;k++)
			{
				sum += this->values[i][k] * otherOperand.values[k][j];
			}
			result.values[i][j] = sum;
		}
}
void MatrixType::Print(ofstream& outfile)
//pre: output file을 정한다.
//post: 행렬 원소를 output file에 출력한다.
{
	for (int i = 0; i < this->numRows;i++)
	{
		for (int j = 0;j < this->numCols;j++)
		{
			outfile << this->values[i][j] << " ";
		}
		outfile << endl;
	}
}

void MatrixType::Print_console() const
{
	for (int i = 0; i < this->numRows;i++)
	{
		for (int j = 0;j < this->numCols;j++)
		{
			cout << values[i][j] << " ";
		}
		cout << endl;
	}
}


bool MatrixType::AddSubCompatible(MatrixType otherOperand)
//pre: 두 행렬에 대해서
//post: 더하기나 빼기 연산이 가능한지 알려준다.
{
	return (this->numRows == otherOperand.numRows && this->numCols == otherOperand.numCols);
}

bool MatrixType::MultCompatible(MatrixType otherOperand)
//pre:  두 행렬에 대해서
//post: 곱하기가 가능한지 알려준다. 
{
	return (this->numCols == otherOperand.numRows);
}