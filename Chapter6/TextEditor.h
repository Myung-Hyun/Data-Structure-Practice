#pragma once
#include <string>

struct LineType;

class TextEditor
{
public:
	TextEditor();
	void GoToTop();
	void GoToBottom();
	void InsertLine(char newline[]);

private:
	LineType* currentLine;
};

TextEditor::TextEditor()
{
	
	LineType* Header;
	LineType* Trailer;

	Header = new LineType;
	Trailer = new LineType;

	strcpy(Header->info, "---Top of file---");
	Header->next = Trailer;
	Header->back = NULL;

	strcpy(Trailer->info, "---Bottom of file---");
	Trailer->next = NULL;
	Trailer->back = Trailer;

	currentLine = Header;
}

//d. O(1)인 경우는 비어있거나, 이미 currentLine이 Top을 가리키고 있는 경우다.

void TextEditor::GoToTop()
{
	while(currentLine->back !=NULL)
	{
		currentLine = currentLine->back;
	}

	if (currentLine->next->next != NULL) //비어있지 않으면 Header 아니라 바로 아래 가리킨다.
	{
		currentLine = currentLine->next;
	}
}

void TextEditor::GoToBottom()
{
	while (currentLine->next != NULL)
	{
		currentLine = currentLine->next;
	}

	if (currentLine->back->back != NULL) 
	{
		currentLine = currentLine->back;
	}
}

//currentLine으로 insert할 위치 계속 가리키도록 한다.
void TextEditor::InsertLine(char newline[])
{
	LineType* temp;
	temp = new LineType;
	strcpy(temp->info, newline);

	temp->next = currentLine->next;
	temp->back = currentLine;
	currentLine->next = temp;
	currentLine->next->back = temp;
	currentLine = temp; //혹은 currentLine->next;
}

struct LineType
{
	LineType* back;
	char info[80];
	LineType* next;
};



