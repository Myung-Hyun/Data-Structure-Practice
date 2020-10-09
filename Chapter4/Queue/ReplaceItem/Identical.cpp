#include <iostream>
#include "QueType.h"
using namespace std;

bool Identical(QueType queue1, QueType queue2);



int main()
{
	QueType queue1;
	QueType queue2;

	for (int i = 0; i < 10;i++)
	{
		queue1.Enqueue(i);
		queue2.Enqueue(i);
	}

	cout << queue1.Identical(queue2) << endl; //Dequeue�ϱ� ���� Ȯ���ؾ� �Ѵ�.
	//cout << Identical(queue1, queue2) << endl;

	
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

	return 0;
}

//�Է� �Ķ���͸� reference�� �ƴ϶� value�� ���ָ� ��������ڰ� ȣ��ȴ�. ��������ڸ� ���� �������� ������
//default�� ���Ǵµ�, �̶��� ���� ���簡�ȴ�. �� �����Ҵ� ��������� ���� ��, �ּҸ� �����ϰԵǰ�, ���������μ� �Ҹ�Ǹ� ���� ��ü�� �����ʹ� ����Ű�� ���� �Ҵ´�.
//(��������ڴ� �ϳ��� ���� �� �ִ�.) �̷� ��� ���� ���縦 �ϵ��� ��������ڸ� �����ؾ� �Ѵ�.
bool Identical(QueType queue1, QueType queue2)
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




/* �Է��Ķ���ͷ� reference ���� �ӽ�ť�� ��������� �Ѵ�. 
bool Identical(QueType& queue1, QueType& queue2) 
{
	ItemType item1;
	ItemType item2;
	bool equal;
	bool flag=false;
	QueType tempQue;
	QueType tempQue2;

	while (!queue1.IsEmpty() || !queue2.IsEmpty())
	{
		queue1.Dequeue(item1);
		tempQue.Enqueue(item1);
		queue2.Dequeue(item2);
		tempQue2.Enqueue(item2);
		if (item1 != item2)
		{
			equal = false;
			flag = true;
			//���⼭ �߰��� return �ϸ� ������ ���� ����.
		}
	}

	if (queue1.IsEmpty() && queue2.IsEmpty() && flag!=true)
	{
		equal = true;
	}
	else {
		equal = false;
	}


	if (queue1.IsEmpty())
	{
		while (!queue2.IsEmpty()) //������ �� �̾Ƴ��� ������ �� ������ �����ȴ�.
		{
			queue2.Dequeue(item2);
			tempQue2.Enqueue(item2);
		}
	}
	else
	{
		while (!queue1.IsEmpty())
		{
			queue1.Dequeue(item1);
			tempQue.Enqueue(item1);
		}
	}
	
	while (!tempQue.IsEmpty()) //����
	{
		tempQue.Dequeue(item1);
		queue1.Enqueue(item1);
	}
	while (!tempQue2.IsEmpty()) //����
	{
		tempQue2.Dequeue(item2);
		queue2.Enqueue(item2);
	}


	return equal;
}
*/