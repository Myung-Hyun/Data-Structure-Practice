// StrTypeAugmented.h
// Contains both header file and implementation file for StrType class
// Contains overloaded operators necessary for Real Estate Program
#pragma once
#include <fstream>
#include <iostream>

#include <cctype>
#include <cstring>

const int MAX_CHARS = 100;

enum InType {ALPHA_NUM, ALPHA, NON_WHITE, NOT_NEW};
class StrType
{
public:
// Assumptions:
    // CharType is a data type consisting of the following constants:
    //   ALPHA:     only alphabetic characters are stored;
    //   ALPHA_NUM: only alphanumeric characters arr stored;
    //   NON_WHITE: all non-white space characters are stored;
    //   NOT_NEW:   all characters excluding the newline character are stored.
    // If skip is true, characters not allowed are skipped until the first
    //   allowed character is found.  Reading and storing begins with this
    //   character and continues until a character not allowed is encountred.
    //   This character is read but not stored.  If skip is false, reading and
    //   storing begins with the current character in the stream.

    void MakeEmpty();
    void GetString(const bool skip, InType charsAllowed);
    //Post: If the number of allowable characters exceeds MAX_CHARS, the
    //      remaining allowable characters have been read and discarded.

    void GetStringFile(bool skip, InType charsAllowed, std::ifstream&  inFile);
    //Post: If the number of allowable characters exceeds maxCHARS, the
    //      remaining allowable characters have been read and discarded.

    void PrintToScreen(const bool newLine) const;
    void PrintToFile(const bool newLine, std::ofstream& outFile) const;
    void CopyString(StrType&  newString);
    bool operator<(StrType otherString)const;
    bool operator==(StrType otherString)const;
    int LengthIs();
    void operator=(const StrType& otherString);
    StrType();
    // Default constructor; maximum is 50 characters per string.

private:
    char letters[MAX_CHARS + 1];
};









