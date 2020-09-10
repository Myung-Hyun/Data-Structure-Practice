#pragma once
// Header file for class StrType, a specification for the
// String ADT given in Chapter 2.
#include <fstream>
#include <iostream>


const int MAX_CHARS = 100;

enum RelationType { LESS, EQUAL, GREATER };
enum InType { ALPHA_NUM, ALPHA, NON_WHITE, NOT_NEW };
class StrType
{
public:
	// Assumptions:		
	// InType is a data type consisting of the following constants:
	// ALPHA: only alphabetic characters are stored;
	// ALPHA_NUM: only alphanumeric characters are stored;
	// NON_WHITE: all non-whitespace characters are stored;
	// NOT_NEW: all characters excluding the newline character
	// are stored.
	// If skip is true, characters not allowed are skipped until the
	// first allowed character is found. Reading and storing
	// begins with this character and continues until a character
	// not allowed is encountered. This character is read but not
	// stored. If skip is false, reading and storing begins with
	// the current character in the stream.
	void MakeEmpty();
	// void GetString(bool skip, InType charsAllowed);
	 // Post: If the number of allowable characters exceeds
	 //       MAX_CHARS, the remaining allowable characters have
	 //       been read and discarded.

	void GetStringFile(bool skip, InType charsAllowed, std::ifstream& inFile);
	//Post: If the number of allowable characters exceeds
	//      MAX_CHARS, the remaining allowable characters have been
	//      read and discarded.

	void PrintToScreen(bool newLine);
	void PrintToFile(bool newLine, std::ofstream& outFile);
	void CopyString(StrType& newString);
	int LengthIs();
	RelationType ComparedTo(StrType& otherString);
	RelationType ComparedTo(StrType otherString);  //같은 이름을 가지고 다른 매개변수를 갖는 함수(오버로딩)


private:
	char letters[MAX_CHARS + 1];
};
