#pragma once
const int MAX_ITEMS = 200;

class doublestack
{
private:
	int top_small; //1000���� �۰ų� ���� ������ top
	int top_big; // 1000���� ū ������ top
	int items[MAX_ITEMS];
public:
	doublestack();
	void Push(int item); //C���� ������ push ����
	void Print(); //stack �� ��Ȳ�� ������ �� �ִ� �Լ�(ä����)
	bool IsFull();
};

