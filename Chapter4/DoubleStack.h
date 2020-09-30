#pragma once
const int MAX_ITEMS = 200;

class doublestack
{
private:
	int top_small; //1000보다 작거나 같은 스택의 top
	int top_big; // 1000보다 큰 스택의 top
	int items[MAX_ITEMS];
public:
	doublestack();
	void Push(int item); //C에서 구현할 push 연산
	void Print(); //stack 의 상황을 보여줄 수 있는 함수(채점시)
	bool IsFull();
};

