#include "StrTypeAugmented.h"
#include <string.h>
// Includes only those functions coded in Chapter 2 plus the relational
// operators == and <.  This implementation file is not complete.
// Unimplemented functions have been commented out.


// Prototypes of auxiliary functions.
// Note: If skip is true, non-allowable leading characters are skipped
//       If end-of-file is encountered while skipping characters, the
//       empty string is returned.
//       If the number of allowable characters exceeds MAX, the rest are
//       read and discarded.

void  GetAlphaNum(bool skip, char letters[]);
// Post: letters array contains only alphabetic characters and numbers.

// void  GetAlpha(bool skip, char letters[]);
// Post: letters array contains only alphabetic characters.

// void  GetNonWhite(bool skip, char letters[]);
// Post: letters array contains only non-white space characters.

void  GetTilNew(bool skip, char letters[]);
// Post: letters array contains everything up to the newline character.

void  GetAlphaNumFile(bool skip, char letters[], std::ifstream& inFile);
// Post: letters array contains only alphabetic characters and numbers.

// void  GetAlphaFile(bool skip, char letters[], std::ifstream& inFile);
// Post: letters array contains only alphabetic characters.

// void  GetNonWhiteFile(bool skip, char letters[], std::ifstream& inFile);
// Post: letters array contains only non-white space characters.

void  GetTilNewFile(bool skip, char letters[], std::ifstream& inFile);
// Post: letters array contains everything up to the newline character.

void StrType::GetString(bool skip, InType charsAllowed)
{
  switch (charsAllowed)
  {
    case ALPHA_NUM : GetAlphaNum(skip, letters);
                     break;
//  case ALPHA     : GetAlpha(skip, letters);
//	                 break;
//  case NON_WHITE : GetNonWhite(skip, letters);
//                   break;
    case NOT_NEW   : GetTilNew(skip, letters);
			         break;
  }
}

void  GetAlphaNum(bool skip, char letters[])
{
  using namespace std;
  char letter;
  int count = 0;

  if (skip)
  {
    cin.get(letter);
    while (!isalnum(letter) && cin)
	cin.get(letter);
  }
  else
    cin.get(letter);
  if (!cin || !isalnum(letter))
     letters[0] = '\0';

   else
   {
     do
     {
       letters[count] = letter;
       count++;
       cin.get(letter);
    } while (isalnum(letter) && cin && (count < MAX_CHARS));
    letters[count] = '\0';
    // Skip extra characters if necessary.
    if (count == MAX_CHARS)
	do
	{
        cin.get(letter);
      } while (isalnum(letter) && cin);
  }
}


void  GetTilNew(bool skip, char letters[])
{
  using namespace std;
  char letter;
  int count = 0;

  if (skip)
  {
    cin.get(letter);
    while ((letter == '\n') && cin)
      cin.get(letter);
  }
  else
    cin.get(letter);
    if (!cin || letter == '\n')
	letters[0] = '\0';

    else
    {
	do
	{
        letters[count] = letter;
        count++;
        cin.get(letter);
      } while ((letter != '\n') && cin && (count < MAX_CHARS));
      letters[count] = '\0';
      // Skip extra characters if necessary.
      if (count == MAX_CHARS)
        do
        {
          cin.get(letter);
        } while ((letter == '\n') && cin);
  }
}

bool StrType::operator<(StrType otherString) const
{
  int result;

  result = std::strcmp(letters, otherString.letters);
  if (result < 0)
    return true;
  else
    return false;
}

bool StrType::operator==(StrType otherString) const
{
  int result;

  result = std::strcmp(letters, otherString.letters);
  if (result == 0)
    return true;
  else
    return false;
}

void StrType::CopyString(StrType& newString)
{
  strcpy_s(newString.letters, letters);
}

void StrType::operator=(const StrType& otherString)
{
  strcpy_s(letters, otherString.letters);  
}

void StrType::PrintToScreen(bool newLine) const
{
  using namespace std;
  if (newLine)
    cout  << endl;
  cout  << letters;
}

void StrType::PrintToFile(bool newLine, std::ofstream& outFile) const
{
  if (newLine)
    outFile  << std::endl;
  outFile  << letters;
}

void StrType::MakeEmpty()
{
  letters[0] = '\0';
}

StrType::StrType()
{
  letters[0] = '\0';
}

int StrType::LengthIs()
{
  return std::strlen(letters);
}

void StrType::GetStringFile(bool skip, InType charsAllowed, 
                                        std::ifstream& inFile)
{
  switch (charsAllowed)
  {
    case ALPHA_NUM : GetAlphaNumFile(skip, letters, inFile);
 			         break;
//  case ALPHA     : GetAlphaFile(skip, letters, inFile);
//                   break;
//  case NON_WHITE : GetNonWhiteFile(skip, letters, inFile);
//                   break;
    case NOT_NEW   : GetTilNewFile(skip, letters, inFile);
			         break;
  }
}

void GetAlphaNumFile(bool skip, char letters[], 
                                     std::ifstream& inFile)
{
  using namespace std;
  char letter;
  int count = 0;

  if (skip)
  {
    inFile.get(letter);
    while (!isalnum(letter) && inFile)
      inFile.get(letter);
  }
  else
    inFile.get(letter);
  if (!inFile || !isalnum(letter))
    letters[0] = '\0';
  else
  {
    do
    {
      letters[count] = letter;
      count++;
      inFile.get(letter);
    } while (isalnum(letter) && inFile && (count < MAX_CHARS));
    letters[count] = '\0';

    // Skip extra characters if necessary.
    if (count == MAX_CHARS)
      do
      {
        inFile.get(letter);
      } while (isalnum(letter) && inFile);
  }
}

void  GetTilNewFile(bool skip, char letters[], 
                                       std::ifstream&  inFile)
{
  char letter;
  int count = 0;

  if (skip)
  {
    inFile.get(letter);
    while ((letter == '\n') && inFile)
      inFile.get(letter);
  }
  else
    inFile.get(letter);
    if (!inFile || letter == '\n')
      letters[0] = '\0';
    else
    {
      do
      {
	  letters[count] = letter;
        count++;
        inFile.get(letter);
      } while ((letter != '\n') && inFile && (count < MAX_CHARS));
      letters[count] = '\0';
      // Skip extra characters if necessary.
      if (count == MAX_CHARS)
        do
        {
          inFile.get(letter);
        } while ((letter == '\n') && inFile);
  }
}


