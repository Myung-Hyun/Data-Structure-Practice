// CLIENT PROGRAM 
// This program manipulates real estate property listings. 
#include <iostream> 
#include "sorted.h"       // Gain access to Sorted List ADT. 
#include <fstream> 
#include <string>


enum CommandType {ADD, DELETE, PRINT_ONE, PRINT_ALL, QUIT};
// Each constant represents a task. 
void FileToList(SortedType&, std::ifstream&);
// moves houses from file to list 
void ListToFile(SortedType, std::ofstream&);
// moves houses from list to file 
void AddHouse(SortedType&);
// adds a house to the list 
void DeleteHouse(SortedType&);
// removes a house from the list 
void PrintHouse(SortedType);
// prints a specific owner listing 
void PrintOwners(SortedType);
// prints a sorted list of owners 
void GetCommand(CommandType&);
// prompts for and gets next command 

using namespace std;
int main() 
{

  ifstream masterIn; // master file of houses (input) 
  ofstream masterOut; // master file of houses (output) 
  CommandType command; 
  SortedType houseList;

  FileToList(houseList, masterIn); 

  GetCommand(command); 
  // Read and process commands until user enters a quit command. 
 

  while (command != QUIT) 
  {
    switch (command) 
    {
      case ADD       : AddHouse(houseList);
                       break; 
      case DELETE    : DeleteHouse(houseList);
                       break; 
      case PRINT_ONE : PrintHouse(houseList);
                       break;
      case PRINT_ALL : PrintOwners(houseList);
                       break; 
    } 
    GetCommand(command); 
  }

  ListToFile(houseList, masterOut); 
  return 0; 
}

//*************************************************************
// **************** Second Level Functions ********************

void FileToList(SortedType& houseList, std::ifstream& masterIn) 
// Pre:  masterIn has not been opened. 
// Post: houseList contains items from masterIn. 
//       masterIn has been closed. 
{
  ItemType item;
  string  inFileName;

  // Prompt for file names, read file names, and prepare files
  cout << "Enter name of file of houses; press return." << endl;
  cin  >> inFileName;
  masterIn.open(inFileName.c_str());

  item.GetFromFile(masterIn);  // Reads one item from masterIn.
  while (masterIn) 
  {
    houseList.InsertItem(item);
    item.GetFromFile(masterIn);
  }
  masterIn.close();
}

void ListToFile(SortedType houseList, std::ofstream& masterOut) 
// Pre:  masterOut has not been opened. 
//       houseList has been initialized. 
// Post: houseList has been written on masterOut. 
//       masterOut has been closed. 
{
  ItemType item; 
  int length;
  string outFileName;
  cout << "Enter name of output file; press return." << endl;
  cin  >> outFileName;
  masterOut.open(outFileName.c_str());

  houseList.ResetList(); 
  length = houseList.LengthIs(); 

  for (int count = 1; count <= length; count++) 
  {
    houseList.GetNextItem(item); 
    item.WriteToFile(masterOut); 
  }

  masterOut.close(); 
}

void AddHouse(SortedType& houseList) 
// Pre:  houseList has been initialized. 
// Post: A house has been added to the list if the names are 
//       not duplicated; otherwise the operation is aborted with 
//       message to user. 
{
  using namespace std;
  bool found; ItemType item;

  item.GetFromUser(); 
  houseList.RetrieveItem(item, found); 
  if (!found) 
  {
    houseList.InsertItem(item);
    cout << "Operation completed."  << endl; 
  }
  else
    cout << "Duplicate name; operation aborted" << endl; 
}

void DeleteHouse(SortedType& houseList) 
// Pre:  houseList has been initialized. 
// Post: A house, specified by user input, is no longer in the list. 
{
  using namespace std;
  bool found; ItemType item;

  item.GetNameFromUser(); 
  houseList.RetrieveItem(item, found); 
  if ( found) 
  {
     houseList.DeleteItem(item); 
     cout << "Operation completed." << endl; 
  } 
  else
    cout << "Person not in list." << endl; 
}

void PrintHouse(SortedType houseList) 
// Pre:  houseList has been initialized. 
// Post: If owner, specified by user input, is in houseList, 
//       house info is printed on the screen. 
{
  using namespace std;
  bool found; ItemType item;
  
  item.GetNameFromUser(); 
  houseList.RetrieveItem(item, found); 
  if ( found)
    item.PrintHouseToScreen(); 
  else
    cout << "Owner not in list." << endl; 
}

void PrintOwners(SortedType houseList) 
// Pre:  houseList has been initialized. 
// Post: Owners' names are printed on the screen.
{
  using namespace std;
  ItemType item;
  int length;

  houseList.ResetList(); 
  length = houseList.LengthIs(); 
  for (int count = 1; count <= length; count++) 
  {
     houseList.GetNextItem(item); 
     item.PrintNameToScreen(); } 
     cout << "Operation completed." << endl; 
  }

void GetCommand(CommandType& command) 
// Pre:  None 
// Post: User command has been prompted for and input; a valid 
//       command has been found. 
{
  using namespace std;
  // Prompt.
  cout << "Operations are listed below. " 
       << "Enter the appropriate uppercase letter and " 
       << "press return."  << endl; 
  cout << "A : Add a house to the list of houses." << endl; 
  cout << "D : Delete a specific owner's house."  << endl; 
  cout << "P : Print the information about an owner's house." 
       << endl; 
  cout << "L : Print all the names on the screen." 
       << endl; 
  cout << "Q : Quit processing."  << endl;
    // Input command. 
  char letter; 
  cin >> letter;
                  
  bool ok = false; 
  while (!ok)
  {
    ok = true;
    switch (letter) 
    {
      case 'A' : command = ADD;
                 break;
      case 'D' : command = DELETE;
                 break;
      case 'P' : command = PRINT_ONE;
                 break;
      case 'L' : command = PRINT_ALL;
                 break;
      case 'Q' : command = QUIT;
                 break;
      default  : cout << "Letter entered is not one of the "
                        << "specified uppercase commands. " 
                        << "Reenter and press return."
                        << endl;
                   cin >> letter; 
                   ok = false; break;
    }
  }
}


