#include "QueType.h"

int main() {
	// ���� �ʱ�ȭ
	char input[INPUT_MAX_SIZE];
	bool isPalindromes = true;
	

	// To-Do 1: INPUT_MAX_SIZE�� �����Ͽ� QueType ���� queue, reverseQueue�ʱ�ȭ 
	QueType queue(INPUT_MAX_SIZE);
	QueType reverseQueue(INPUT_MAX_SIZE);

	// To-Do 3: input������ �Է¹ޱ� 
	cin >> input;
	
	string input_new;
	int length = strlen(input);
	input_new.reserve(length);
	for (int i = 0; i < length; i++)
	{
		if (input[i] != ',' && input[i] != ' ' && input[i] != '!' && input[i] != '\'' && input[i] != '.') //�����ȣ�� ���� �ƴҶ��� �ִ´�.
		{
			input_new += tolower(input[i]); //��ҹ��� ���� ����.
		}
	}

	length = input_new.length();

	// To-Do 4: queue, reverseQueue�� enqueue
	
	for (int i = 0; i < length; i++) {
		// Code Here
		queue.Enqueue(input_new[i]);
		reverseQueue.Enqueue(input_new[length - i - 1]);
	}

	// To-Do 5: Palindromes check 
	ItemType item, reverseItem;
	while (true) { 
		
		// ���������� ������ queue�� length == 0�̰ų� (0�϶����� �ٸ� �� �����Ƿ� true)
		// dequeue�� ItemType�� ���� �ٸ� ��� 
		if (length == 0)
		{
			isPalindromes = true;
			break;
		}
		queue.Dequeue(item);
		reverseQueue.Dequeue(reverseItem);

		if (item!=reverseItem)
		{
			isPalindromes = false;
			break;
		}
		length--;
	}

	// ���
	if (isPalindromes) cout << "O" << endl;
	else cout << "X" << endl;

	return 0;
}