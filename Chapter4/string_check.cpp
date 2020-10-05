#include "StackType.h"
#include <iostream>
#include <string>

using namespace std;


// 반복문과 Stack을 이용하여 입력 받은 괄호가 올바른 괄호 문자열인지 판단
// 아래의 사항은 is_balance가 false
// 예외사항 1. ( ) 의 짝이 안맞음
// 예외사항 2. ( 보다 ) 이 많다, 반대의 경우도 동일 => (와 )의 개수 카운팅으로 구현은 X
// 예외사항 3. (보다 )이 먼저 나와서 먼저 닫아버림

int main()
{
    string symbol;
    StackType stack;
    bool is_balance = true;

    cin >> symbol;
	int length = symbol.length(); //cin으로 받은 문자열 길이 구할 때는 strlen 못 쓰고, 멤버함수 length() 사용.

	for (int i = 0; i < length; i++)
	{
		stack.Push(symbol[i]);
	}

	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (stack.Top() == ')')
		{
			count++;
		}
		else
		{
			count--;
		}
		if (count < 0)
		{
			is_balance = false;
		}
		stack.Pop();
	}

	if (count == 0)
	{
		is_balance = true;
	}
	else
	{
		is_balance = false;
	}


    // 결과 출력
	if (is_balance) cout << "O" << endl;
	else cout << "X" << endl;

    return 0;
}
   