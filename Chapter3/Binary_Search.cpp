#include <iostream>
using namespace std;

int BinarySearch(int list[], int size, int item) //배열, 배열크기, 찾고자하는 integer
{
	int midPoint;
	int  first = 0;
	int	last = size - 1;
	bool  moreToSearch = (first <= last);
	bool found = false;

	while (moreToSearch && !found)
	{
		midPoint = (first + last) / 2;

		if (item < list[midPoint])
		{
			last = midPoint - 1;
			moreToSearch = (first <= last);
		}
		else if(item > list[midPoint])
		{
			first = midPoint + 1;
			moreToSearch = (first <= last);
		}
		else
		{
			found = true;
			break;
		}
	}

	if(found ==false)
	{
		return -1;
	}
	return midPoint;
}

int BinarySearch_b(int list[], int size, int item) //찾고자 하는 값보다 작거나 같은 값들 중에서 가장 큰 값을 리턴
{
	int midPoint;
	int  first = 0;
	int	last = size - 1;
	bool  moreToSearch = (first <= last);
	bool found = false;

	while (moreToSearch && !found)
	{
		midPoint = (first + last) / 2;

		if (item < list[midPoint])
		{
			last = midPoint - 1;
			moreToSearch = (first <= last);
		}
		else if (item > list[midPoint])
		{
			first = midPoint + 1;
			moreToSearch = (first <= last);
		}
		else
		{
			found = true;
			break;
		}
	}

	if (found == false)
	{
		if (item < list[midPoint])
			return list[midPoint - 1];
		else
			return list[midPoint];

	}
	return list[midPoint];
}

int BinarySearch_c(int list[], int size, int item) //찾고자 하는 값보다 크거나 같은 값들 중에서 가장 작은 값을 
{
	int midPoint;
	int  first = 0;
	int	last = size - 1;
	bool  moreToSearch = (first <= last);
	bool found = false;

	while (moreToSearch && !found)
	{
		midPoint = (first + last) / 2;

		if (item < list[midPoint])
		{
			last = midPoint - 1;
			moreToSearch = (first <= last);
		}
		else if (item > list[midPoint])
		{
			first = midPoint + 1;
			moreToSearch = (first <= last);
		}
		else
		{
			found = true;
			break;
		}
	}

	if (found == false)
	{
		if (item < list[midPoint])
			return list[midPoint];
		else
			return list[midPoint+1];

	}
	return list[midPoint];
}


int main()
{
	int list[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int result = BinarySearch(list, 10, 11); //10 대신 Sizeof(list)/sizeof(list[0]) 쓰면 바꾸지 않아도 된다.
	cout << result << endl; // -1 리턴
	result = BinarySearch(list, 10, 7);
	cout << result << endl; // 6 리턴(몇번 째 있는지, index)


	int list2[7] = {2,4,5,6,8,9,10};
	result = BinarySearch_b(list2, 7, 7);
	cout << result << endl; // 6 리턴

	result = BinarySearch_c(list2, 7, 7);
	cout << result << endl; // 8 리턴


	return 0;
}
