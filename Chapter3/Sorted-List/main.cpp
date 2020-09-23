#include <iostream>
#include "SortedType.h"

using namespace std;

int main()
{
    SortedType sorted_list;
    
    
    // Input row, col, index
    ItemType temp;
    int row, col;
    int index;
    cin >> row >> col;
    cin >> index;
    
 
    // row, col만큼의 2차원 ItemType array를 할당
    ItemType** data = NULL;
	data = new ItemType *[row];
	for (int i = 0; i < row ;i++)
		data[i] = new ItemType[col];

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			temp.Initialize((i + 1) * (j + 1));
			data[i][j] = temp ;
		}
	}


    // sorted_list에 item insert 후 resetlist
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			sorted_list.InsertItem(data[i][j]);
		}
	}
    sorted_list.ResetList();
    
    //Get next item으로 해당인덱스로 접근
	for (int i = 0; i < index; i++) // index번 수행하면 1차원 배열에서 index번 째 원소 가져옴, c++에선 index-1번째로 인식. 
	{
		sorted_list.GetNextItem(temp);
	}
    
    // 출력
	temp.Print(cout);


	for (int i = 0; i < row; i++)
		delete[] data[i];
	delete[] data;

    return 0;
}
