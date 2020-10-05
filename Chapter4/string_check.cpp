#include "StackType.h"
#include <iostream>
#include <string>

using namespace std;


// �ݺ����� Stack�� �̿��Ͽ� �Է� ���� ��ȣ�� �ùٸ� ��ȣ ���ڿ����� �Ǵ�
// �Ʒ��� ������ is_balance�� false
// ���ܻ��� 1. ( ) �� ¦�� �ȸ���
// ���ܻ��� 2. ( ���� ) �� ����, �ݴ��� ��쵵 ���� => (�� )�� ���� ī�������� ������ X
// ���ܻ��� 3. (���� )�� ���� ���ͼ� ���� �ݾƹ���

int main()
{
    string symbol;
    StackType stack;
    bool is_balance = true;

    cin >> symbol;
	int length = symbol.length(); //cin���� ���� ���ڿ� ���� ���� ���� strlen �� ����, ����Լ� length() ���.

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


    // ��� ���
	if (is_balance) cout << "O" << endl;
	else cout << "X" << endl;

    return 0;
}
   