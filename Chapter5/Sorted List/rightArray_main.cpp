#include "SortedType.h"
#include <iostream>

using namespace std;

/*
Program Description
App 06
배열의 길이 N을 입력받음
N개의 숫자를 입력받음
N개의 숫자에 올바른 배열이 되는 배열이 있는지 확인
*/

int main() {
	SortedType<int> StoreArray;
	int arrayLength;
	int temp;
	bool rightArray=false;

	//배열의 길이 N과 N개의 숫자을 입력받는 코드 작성
	cin >> arrayLength;
	for (int i = 0; i < arrayLength; i++)
	{
		cin >> temp;
		StoreArray.InsertItem(temp);
	}

	//리스트의 item들이 올바른 배열이 있는지 검사하는 코드 작성
	//i와 i+4번째 차이가 4가 나는 경우가 있는지 확인한다. 
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
	

	//검사 결과를 출력하는 코드 작성
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