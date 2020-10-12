#include "QueType.h"

int main() {
	// 변수 초기화
	char input[INPUT_MAX_SIZE];
	bool isPalindromes = true;
	

	// To-Do 1: INPUT_MAX_SIZE를 전달하여 QueType 변수 queue, reverseQueue초기화 
	QueType queue(INPUT_MAX_SIZE);
	QueType reverseQueue(INPUT_MAX_SIZE);

	// To-Do 3: input변수에 입력받기 
	cin >> input;
	
	string input_new;
	int length = strlen(input);
	input_new.reserve(length);
	for (int i = 0; i < length; i++)
	{
		if (input[i] != ',' && input[i] != ' ' && input[i] != '!' && input[i] != '\'' && input[i] != '.') //문장기호가 전부 아닐때만 넣는다.
		{
			input_new += tolower(input[i]); //대소문자 구분 안함.
		}
	}

	length = input_new.length();

	// To-Do 4: queue, reverseQueue에 enqueue
	
	for (int i = 0; i < length; i++) {
		// Code Here
		queue.Enqueue(input_new[i]);
		reverseQueue.Enqueue(input_new[length - i - 1]);
	}

	// To-Do 5: Palindromes check 
	ItemType item, reverseItem;
	while (true) { 
		
		// 빠져나오는 조건은 queue의 length == 0이거나 (0일때까지 다른 것 없으므로 true)
		// dequeue한 ItemType의 값이 다른 경우 
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

	// 출력
	if (isPalindromes) cout << "O" << endl;
	else cout << "X" << endl;

	return 0;
}