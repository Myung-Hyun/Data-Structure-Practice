#include "SortedType.h"
#include <iostream>

using namespace std;

/*
Program Description
App 06
�迭�� ���� N�� �Է¹���
N���� ���ڸ� �Է¹���
N���� ���ڿ� �ùٸ� �迭�� �Ǵ� �迭�� �ִ��� Ȯ��
*/

int main() {
	SortedType<int> StoreArray;
	int arrayLength;
	int temp;
	bool rightArray=false;

	//�迭�� ���� N�� N���� ������ �Է¹޴� �ڵ� �ۼ�
	cin >> arrayLength;
	for (int i = 0; i < arrayLength; i++)
	{
		cin >> temp;
		StoreArray.InsertItem(temp);
	}

	//����Ʈ�� item���� �ùٸ� �迭�� �ִ��� �˻��ϴ� �ڵ� �ۼ�
	//i�� i+4��° ���̰� 4�� ���� ��찡 �ִ��� Ȯ���Ѵ�. 
	int item0=0;
	int item4=0;
	

	for (int i = 0; i < arrayLength-4;i++)
	{
		StoreArray.ResetList();
		for (int j = 0; j <= i;j++)
		{
			StoreArray.GetNextItem(item0);
		}
		

		StoreArray.ResetList();
		for (int j = 0; j <= i + 4;j++)
		{
			StoreArray.GetNextItem(item4);
		}

		if (item4 - item0 == 4)
		{
			rightArray = true;
			break;
		}
		else
		{
			rightArray = false;
		}
	}
	

	//�˻� ����� ����ϴ� �ڵ� �ۼ�
	if (rightArray == true)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}

	return 0;
}