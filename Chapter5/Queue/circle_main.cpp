#include <iostream>
#include "QueType.h"
using namespace std;


int main()
{
	QueType<int> queue;
	QueType<int> tempQue;
	QueType<int> tempQue2;

	int N, K;
	int temp=0;

	cin >> N >> K;

	for (int i = 0; i < N;i++)
	{
		queue.Enqueue(i + 1);
	}


	for(int i=0;i<N-K+1;i++)
	{
		for (int i = 0; i < K - 1;i++)
		{

			queue.Dequeue(temp);
			tempQue.Enqueue(temp);
		}

		queue.Dequeue(temp);
		cout << temp;

		for (int i = 0; i < K - 1;i++)
		{
			tempQue.Dequeue(temp);
			queue.Enqueue(temp);
		}
	}

	queue.Dequeue(temp);
	cout << temp; //��������� ��� N, K�����ؼ� ����.

	//K-2���� ���ؼ��� �Ϲ����� �˰��� ����� ����� �����س��� ���߽��ϴ�.



	return 0;
}