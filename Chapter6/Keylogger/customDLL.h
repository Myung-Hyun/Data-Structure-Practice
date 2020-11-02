#pragma once
#include <iostream>
using namespace std;
typedef char ItemType;
#define STX 2
#define ETX 3

struct LineType
{
    ItemType info;
    LineType* next;
    LineType* back;
};

class customDLL
{
public:
    //==================================== FIX function START
    customDLL();     // Class constructor	
    ~customDLL();    // Class destructor
    bool IsFull() const;
    // Determines whether list is full.
    // Post: Function value = (list is full)

    int  LengthIs() const;
    // Determines the number of elements in list.
    // Post: Function value = number of elements in list.

    void MakeEmpty();
    // Initializes list to empty state.
    // Post:  List is empty.

    void InsertItem(ItemType item);
    // Adds item to list.
    // Pre:  List is not full.
    //       item is not in list. 
    // Post: item is in list.

    void GetNextItem(ItemType& item);
    // Gets the next element in list.
    // Pre:  Current position is defined.
    //       Element at current position is not last in list.
    // Post: Current position is updated to next position.
    //       item is a copy of element at current position.
    //==================================== FIX functions END

    //==== Example functions can be added, deleted and modified if necessary
    void GoToHeader();
    // Move the currentLine cursor to the 0th node.
    void GoToBottom();
    // Move the currentLine cursor to the (last-1)th node for insert
    void MoveLeft();
    // Move to the left by the entered parameter.
    void MoveRight();
    // Move to the right by the entered parameter.
    void BackSpace();

    void Delete();
    // Delete the node pointed to by currentLine and move currentLine to the left node
    void Print();
    // For DEBUG,
    ItemType* Decoding();
    // Write this function by using or changing the above function

private:
    LineType* listData;
    int length;
    LineType* currentLine;
};

