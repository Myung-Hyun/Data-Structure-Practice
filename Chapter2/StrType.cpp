#include <cctype>
#include <fstream>
#include <iostream>
#include <cstring>

#include "StrType.h"
#include <cctype> 
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

// Prototypes of auxiliary functions.
// Note: If skip is true, non-allowable leading characters are
//  skipped. If end-of-file is encountered while skipping
//  characters, the empty string is returned. If the number
//  of allowable characters exceeds MAX_CHARS, the rest are
//  read and discarded.

void GetAlphaNum(bool skip, char letters[], std::ifstream& inFile);
// Post: letters array contains only alphanumeric characters.

//void GetAlpha(bool skip, char letters[], std::ifstream& inFile);
// Post: letters array contains only alphabetic characters.

//void GetNonWhite(bool skip, char letters[], std::ifstream& inFile);
// Post: letters array contains only non-whitespace characters.

void GetTilNew(bool skip, char letters[], std::ifstream& inFile);
// Post: letters array contains everything up to newline character.

void StrType::GetStringFile(bool skip, InType charsAllowed, std::ifstream& inFile)
{
	switch (charsAllowed)
	{
	case ALPHA_NUM: GetAlphaNum(skip, letters, inFile);
		break;
		//    case ALPHA     : GetAlpha(skip, letters, inFile);
		//                     break;
		//    case NON_WHITE : GetNonWhite(skip, letters, inFile);
		 //                    break;
	case NOT_NEW: GetTilNew(skip, letters, inFile);
		break;
	}
}

void GetAlphaNum(bool skip, char letters[], std::ifstream& inFile)
// Post: If skip is true, non-alphanumeric letters are skipped.
//       Alphanumeric characters are read and stored until a
//       non-alphanumeric character is read or MAX_CHARS characters
//       have been stored. If the stream is not in the fail state,
//       the last character read was a non-alphanumeric character.
{
	using namespace std;
	char letter;
	int count = 0;

	if (skip)
	{// skip non-alphanumeric characters
		inFile.get(letter);
		while (!isalnum(letter) && inFile)
			inFile.get(letter);
	}
	else
		inFile.get(letter);
	if (!inFile || !isalnum(letter))
		// No legal character found; empty string returned.
		letters[0] = '\0';
	else
	{// Read and collect characters.
		do
		{
			letters[count] = letter;
			count++;
			inFile.get(letter);
		} while (isalnum(letter) && inFile && (count < MAX_CHARS));

		letters[count] = '\0';
		// Skip extra characters if necessary.
		if (count == MAX_CHARS && isalnum(letter))
			do
			{
				inFile.get(letter);
			} while (isalnum(letter) && inFile);
	}

}

void GetTilNew(bool skip, char letters[], std::ifstream& inFile)
// Post: If skip is true, newline characters are skipped.
//       All characters are read and stored until a newline
//       character is read or MAX_CHARS characters have been
//       stored. If the stream is not in the fail state, the
//       last character read was a newline character.
{
	using namespace std;
	char letter;
	int count = 0;
	if (skip)
	{// skip newlines.
		inFile.get(letter);
		while ((letter == '\n') && inFile)
			inFile.get(letter);
	}
	else
		inFile.get(letter);
	if (!inFile || letter == '\n')
		letters[0] = '\0';
	else
	{// Read and collect characters.
		do
		{
			letters[count] = letter;
			count++;
			inFile.get(letter);
		} while ((letter != '\n') && inFile && (count < MAX_CHARS));

		letters[count] = '\0';
		// Skip extra characters if necessary.
		if (count == MAX_CHARS && letter != '\n')

			do
			{
				inFile.get(letter);
			} while ((letter != '\n') && inFile);
	}
}

void StrType::PrintToScreen(bool newLine)
// Post:  letters has been sent to the output stream.
{
	if (newLine)
		cout << endl;
	cout << letters;
}

void StrType::MakeEmpty()
{
	letters[0] = '\0';
}

void StrType::PrintToFile(bool newLine, ofstream& outFile)
{
	if (newLine)
		outFile << endl;
	outFile << letters;
}

void StrType::CopyString(StrType& newString)
// Post: letters has been copied into newString.letters.
{
	strcpy_s(newString.letters, letters);
}

int StrType::LengthIs()
{
	return strlen(letters);
}


// add by jmh 
RelationType StrType::ComparedTo(StrType& otherString)   //매개변수를 &로 받는 것이 pass by reference
{
	if (strcmp(this->letters,otherString.letters)==-1)
	{
		return LESS; 
	}
	else if (strcmp(this->letters, otherString.letters) == 0)
	{
		return EQUAL;
	}
	else
	{
		return GREATER;
	}
}

RelationType StrType::ComparedTo(StrType otherString) // 비교하는 부분 직접 작성.
{
	int idx = 0;
	int self_len = strlen(this->letters);
	int other_len = strlen(otherString.letters);
	bool result=true; //문자열 비교 중 다른 문자 발견한 시점에 false로 바꾼다.
	
	while (idx == self_len-1 || idx ==other_len-1  )
	{
		if (this->letters[idx] != otherString.letters[idx])
		{
			result = false;
			break; 
		}
		idx++;
	}

	if (result == true && self_len==other_len) //길이가 같고 그 때까지 비교한 문자들이 다 같다면
	{
		return EQUAL;
	}
	else  //다른 경우 대소비교
	{
		if (this->letters[idx] > otherString.letters[idx]) //다른 걸 발견한 시점(idx 값 유지)의 문자를 비교
		{
			return GREATER;
		}
		else
			return LESS;
	}

	
}
