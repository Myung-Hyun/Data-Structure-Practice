#include "ItemType.h" 
// File ItemType.h must be provided by the user of this class. 
//  ItemType.h must contain the following definitions: 
//  MAX_ITEMS:     the maximum number of items on the list 
//  ItemType:      the definition of the objects on the list 
//  RelationType:  {LESS, GREATER, EQUAL}
//  Member function ComparedTo(ItemType item) which returns 
//       LESS, if self "comes before" item 
//       GREATER, if self "comes after" item 
//       EQUAL, if self and item are the same 

class SortedType 
{
public:
  SortedType();
  bool IsFull() const;
  // Function:  Determines whether list is full.
  // Pre:  List has been initialized.
  // Post: Function value = (list is full)

  int LengthIs() const;
  // Function: Determines the number of elements in list.
  // Pre:  List has been initialized.
  // Post: Function value = number of elements in list

  void RetrieveItem(ItemType& item, bool& found);
  // Function: Retrieves list element whose key matches item's key (if
  //           present).
  // Pre:  List has been initialized.
  //       Key member of item is initialized.
  // Post: If there is an element someItem whose key matches
  //       item's key, then found = true and item is a copy of
  //       someItem; otherwise found = false and item is unchanged.
  //       List is unchanged.

  void InsertItem(ItemType item);
  // Function: Adds item to list.
  // Pre:  List has been initialized.
  //       List is not full.
  //       item is not in list.
  //       List is sorted.
  // Post: item is in list.
  //       List is sorted

  void DeleteItem(ItemType item);
  // Function: Deletes the element whose key matches item's key.
  // Pre:  List has been initialized.
  //       Key member of item is initialized.
  //       One and only one element in list has a key matching item's key.
  // Post: No element in list has a key matching item's key.
  //       List is sorted.

  void ResetList();
  // Function: Initializes current position for an iteration through the list.
  // Pre:  List has been initialized.
  // Post: Current position is prior to list.

  void GetNextItem(ItemType& item);
  // Function: Gets the next element in list.
  // Pre:  List has been initialized and has not been changed since last call.
  //       Current position is defined.
  //       Element at current position is not last in list.
  //	     
  // Post: Current position is updated to next position.
  //       item is a copy of element at current position.

private:
  int length;
  ItemType info[MAX_ITEMS];
  int currentPos;
};
