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

	cout << queue1.Identical(queue2) << endl; //Dequeue하기 전에 확인해야 한다.
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

//입력 파라미터를 reference가 아니라 value로 해주면 복사생성자가 호출된다. 복사생성자를 따로 정의하지 않으면
//default가 사용되는데, 이때는 얕은 복사가된다. 즉 동적할당 멤버변수가 있을 때, 주소를 공유하게되고, 지역변수로서 소멸되면 원래 객체의 포인터는 가리키는 곳을 잃는다.
//(복사생성자는 하나만 있을 수 있다.) 이런 경우 깊은 복사를 하도록 복사생성자를 정의해야 한다.
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




/* 입력파라미터로 reference 쓰면 임시큐로 복원해줘야 한다. 
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
			//여기서 중간에 return 하면 복원할 수가 없다.
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
		while (!queue2.IsEmpty()) //끝까지 다 뽑아내야 복원할 때 순서가 유지된다.
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
	
	while (!tempQue.IsEmpty()) //복원
	{
		tempQue.Dequeue(item1);
		queue1.Enqueue(item1);
	}
	while (!tempQue2.IsEmpty()) //복원
	{
		tempQue2.Dequeue(item2);
		queue2.Enqueue(item2);
	}


	return equal;
}
*/