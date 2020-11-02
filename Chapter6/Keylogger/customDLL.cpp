#include "customDLL.h"
#include <iostream>

using namespace std;

customDLL::customDLL()  // Class constructor
{
	length = 0;
	LineType* header = new LineType;
	LineType* tailer = new LineType;

	header->next = tailer;
	tailer->back = header;
	header->back = NULL;
	tailer->next = NULL;
	header->info = STX; // ASCII 2 -> STX
	tailer->info = ETX; // ASCII 3 -> ETX


	listData = header;
	currentLine = header;

}

customDLL::~customDLL()
// Class destructor
{
	MakeEmpty();
}

bool customDLL::IsFull() const
// Returns true if there is no room for another ItemType 
//  on the free store; false otherwise.
{
	LineType* location;
	try
	{
		location = new LineType;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}

int customDLL::LengthIs() const
// Post: Number of items in the list is returned.
{
	return length;
}

void customDLL::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	LineType* tempPtr;

	while (listData != NULL)
	{
		tempPtr = listData;
		listData = listData->next;
		delete tempPtr;
	}
	length = 0;
}


void customDLL::InsertItem(ItemType item)
// item is in the list; length has been incremented.
{
	LineType* location;

	//GoToBottom();

	location = new LineType;
	location->info = item;
	location->back = currentLine;
	location->next = currentLine->next;
	currentLine->next->back = location;
	currentLine->next = location;
	currentLine = location;
	length++;
}


void customDLL::GetNextItem(ItemType& item)
// Post:  Current position has been updated; item is current item.
{
	if (currentLine == NULL)
		currentLine = listData;
	else
		currentLine = currentLine->next;

	item = currentLine->info;
}

//***********************바꿔도 되는 부분***********************************************
void customDLL::GoToHeader() {
	// You can change the code if necessary.
	while (currentLine->back != NULL)
		currentLine = currentLine->back;
}

void customDLL::GoToBottom() {
	// You can change the code if necessary.
	while (currentLine->next != NULL)
		currentLine = currentLine->next;

	currentLine = currentLine->back;
}

void customDLL::MoveLeft() //
{
	// To-Do : Implement move left if necessary
	// Input your code START
	if (currentLine->back != NULL)
	{
		currentLine = currentLine->back;
	}
	// Input your code END
}
void customDLL::MoveRight()  // 
{
	// To-Do : Implement move right if necessary
	// Input your code START
	if (currentLine->next->next != NULL)
	{
		currentLine = currentLine->next;
	}
	// Input your code END
}

void customDLL::BackSpace() //BackSpace가 처음에 있는 경우 예외 처리해야함
{ 
	// To-Do : Implement Delete if necessary
	// Input your code START	
	if (currentLine->back != NULL)
	{
		LineType* temp;
		temp = currentLine;
		currentLine = currentLine->back;
		currentLine->next = temp->next;
		temp->next->back = currentLine;
		delete temp;

		// Input your code END
		// After that, length is -1
		length--;
	}
}

void customDLL::Delete() //delete가 마지막에 있는 경우 예외 처리해야함
{
	if (currentLine->next->next != NULL)
	{
		LineType* temp;
		temp = currentLine->next;
		currentLine->next = temp->next;
		temp->next->back = currentLine;
		delete temp;

		length--;
	}
}

ItemType* customDLL::Decoding() {
	// To-Do : Implement Delete if necessary
	// Input your code STAR
	ItemType* result = nullptr; //Change to your own initial value
	customDLL Result;

	GoToHeader();
	for (int i = 0; i < length; i++)
	{
		currentLine=currentLine->next;	
		if (currentLine->info == '<')
		{
			Result.MoveLeft();
			
		}
		else if (currentLine->info == '>')
		{
			Result.MoveRight();
		}
		else if (currentLine->info == '-')
		{
			Result.BackSpace();
		}
		else if (currentLine->info == '_')
		{
			Result.Delete();
		}
		else 
		{
			Result.InsertItem(currentLine->info);
		}
	}


	char* decode=nullptr; 
	int mylength = Result.length;
	decode = new char[mylength+1]; //\0 추가하기 위해 length +1

	Result.GoToHeader();
	for (int i = 0;i < mylength; i++)
	{
		Result.currentLine = Result.currentLine->next;
		decode[i] = Result.currentLine->info;
	}
	decode[mylength] = '\0'; // 추가하지 않으면 문자열 끝이 없어서 한자(쓰레기 값) 뜬다.
	result = decode;
	// Input your code END
	// After that, return result
	return result;
}

void customDLL::Print(){
	GoToHeader();
	ItemType tmp;
	for (int i = 0; i < length; i++) {
		GetNextItem(tmp);
		cout << tmp;
	}
	cout << endl;
}