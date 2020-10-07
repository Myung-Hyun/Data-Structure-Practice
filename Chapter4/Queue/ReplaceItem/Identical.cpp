#include <iostream>
#include "QueType.h"
using namespace std;

bool Identical(QueType& queue1, QueType& queue2);



int main()
{
	QueType queue1;
	QueType queue2;

	for (int i = 0; i < 10;i++)
	{
		queue1.Enqueue(i);
		queue2.Enqueue(i+1);
	}

	//cout << queue1.Identical(queue2) << endl; //Dequeue�ϱ� ���� Ȯ���ؾ� �Ѵ�.
	cout << Identical(queue1, queue2) << endl;

	/* Identical�� Client�� �����ϴ� ��� Dequeue�� ����ؼ�, ����ϱ� ���� �Ʒ� �ڵ� �����ϸ� empty ��������.
	for (int i = 0; i < 10; i++)
	{
		ItemType item = 0;
		queue1.Dequeue(item);
		cout << item << " ";
	}
	cout << endl;

	for (int i = 0; i < 10; i++)
	{
		ItemType item = 0;
		queue2.Dequeue(item);
		cout << item << " ";
	}
	*/

	return 0;
}


bool Identical(QueType& queue1, QueType& queue2)
{
	ItemType item1;
	ItemType item2;
	bool equal;

	while (!queue1.IsEmpty() || !queue2.IsEmpty())
	{
		queue1.Dequeue(item1);
		queue2.Dequeue(item2);
		if (item1 != item2)
		{
			equal = false;
			return equal;
		}
	}

	if (queue1.IsEmpty() && queue2.IsEmpty())
	{
		equal = true;
		return equal;
	}
	else
	{
		equal = false;
		return equal;
	}

}