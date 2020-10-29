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

//d. O(1)�� ���� ����ְų�, �̹� currentLine�� Top�� ����Ű�� �ִ� ����.

void TextEditor::GoToTop()
{
	while(currentLine->back !=NULL)
	{
		currentLine = currentLine->back;
	}

	if (currentLine->next->next != NULL) //������� ������ Header �ƴ϶� �ٷ� �Ʒ� ����Ų��.
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

//currentLine���� insert�� ��ġ ��� ����Ű���� �Ѵ�.
void TextEditor::InsertLine(char newline[])
{
	LineType* temp;
	temp = new LineType;
	strcpy(temp->info, newline);

	temp->next = currentLine->next;
	temp->back = currentLine;
	currentLine->next = temp;
	currentLine->next->back = temp;
	currentLine = temp; //Ȥ�� currentLine->next;
}

struct LineType
{
	LineType* back;
	char info[80];
	LineType* next;
};



