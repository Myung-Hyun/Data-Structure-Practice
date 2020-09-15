#include <iostream>
#include "MatrixType.h"


MatrixType::MatrixType()
//pre: 2���� matrix�� �ʱ�ȭ �Ǿ���Ѵ�. 
//post: matrix�� 0���� ä������.
{
	for (int i = 0;i < 10;i++)
	{
		for (int j = 0;j < 10;j++)
		{
			this->values[i][j] = 0; //�ʱ�ȭ���� �ʰ� ����ϴ� ��� -858993460 �̷� �� ���.
		}
	}
	numRows = 0;
	numCols = 0;
}

void MatrixType::MakeEmpty()
//pre: ������ matrix�� ���ؼ�
//post: ��� ���Ҹ� 0���� �����.
{
	for (int i = 0;i < 10;i++)
		for (int j = 0;j < 10;j++)
			this->values[i][j] = 0;

}
void MatrixType::SetSize(int rowsSize, int colSize)
//pre: rowsSize, colSize�� 10�̳��� ���̴�.
//post: ��� ���� ũ�⸦ �����ش�. ��� ��ü ���� �Ŀ� �׻� �� �Լ��� �̿��ؼ� ũ�� �����־�� �Ѵ�.
{
	numRows = rowsSize;
	numCols = colSize;
}
void MatrixType::StoreItem(int item, int row, int col)
//pre: ���ϴ� ���� ��ġ(��,��)�� �޴´�.
//post: ���� ���ϴ� ��ġ�� �����Ѵ�.
{
	values[row-1][col-1] = item; //index�� 1 �۴�.
}
void MatrixType::Add(MatrixType otherOperand, MatrixType& result)
//pre: �� ����� ���ؾ� �Ѵ�.
//post: �� ����� ���� ����� result�� �����Ѵ�. 
{
	for (int i = 0;i < this->numRows;i++)
		for (int j = 0;j < this->numCols;j++) {
			result.values[i][j] = this->values[i][j] + otherOperand.values[i][j];
		}
}
void MatrixType::Sub(MatrixType otherOperand, MatrixType& result)
//pre: �� ����� ���� �Ѵ�.
//post: �� ����� �� ����� result�� �����Ѵ�. 
{
	for (int i = 0;i < this->numRows;i++)
		for (int j = 0;j < this->numCols;j++)
			result.values[i][j] = this->values[i][j] - otherOperand.values[i][j];
}
void MatrixType::Mult(MatrixType otherOperand, MatrixType& result)
//pre: �� ����� ���ؾ� �Ѵ�.
//post: �� ����� ���� ����� result�� �����Ѵ�. 
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
//pre: output file�� ���Ѵ�.
//post: ��� ���Ҹ� output file�� ����Ѵ�.
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
//pre: �� ��Ŀ� ���ؼ�
//post: ���ϱ⳪ ���� ������ �������� �˷��ش�.
{
	return (this->numRows == otherOperand.numRows && this->numCols == otherOperand.numCols);
}

bool MatrixType::MultCompatible(MatrixType otherOperand)
//pre:  �� ��Ŀ� ���ؼ�
//post: ���ϱⰡ �������� �˷��ش�. 
{
	return (this->numCols == otherOperand.numRows);
}