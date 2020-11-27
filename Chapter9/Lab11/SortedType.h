// Header file for Unsorted List ADT.  
template <class ItemType>
struct NodeType;

// Assumption:  ItemType is a type for which the operators "<" 
// and "==" are defined-either an appropriate built-in type or
// a class that overloads these operators.

template <class ItemType>
class SortedType
{
public:
  SortedType();     // Class constructor	
  ~SortedType();    // Class destructor

  bool IsFull() const;
  // Determines whether list is full.
  // Post: Function value = (list is full)

  int  LengthIs() const;
  // Determines the number of elements in list.
  // Post: Function value = number of elements in list.

  void MakeEmpty();
  // Initializes list to empty state.
  // Post:  List is empty.

  void RetrieveItem(ItemType& item, bool& found);
  // Retrieves list element whose key matches item's key 
  // (if present).
  // Pre:  Key member of item is initialized.
  // Post: If there is an element someItem whose key matches 
  //       item's key, then found = true and item is a copy 
  //       of someItem; otherwise found = false and item is 
  //       unchanged. 
  //       List is unchanged.
  
  void InsertItem(ItemType item); 
  // Adds item to list.
  // Pre:  List is not full.
  //       item is not in list. 
  // Post: item is in list.

  void DeleteItem(ItemType item);
  // Deletes the element whose key matches item's key.
  // Pre:  Key member of item is initialized.
  //       One and only one element in list has a key matching
  //       item's key.
  // Post: No element in list has a key matching item's key.

  void ResetList();
  // Initializes current position for an iteration through the
  // list.
  // Post: Current position is prior to list.

  void GetNextItem(ItemType&);
  // Gets the next element in list.
  // Pre:  Current position is defined.
  //       Element at current position is not last in list.
  // Post: Current position is updated to next position.
  //       item is a copy of element at current position.

private:
  NodeType<ItemType>* listData;
  int length;
  NodeType<ItemType>* currentPos;
};
template<class ItemType>
struct NodeType
{
    ItemType info;
    NodeType* next;
};
template <class ItemType>
SortedType<ItemType>::SortedType()  // Class constructor
{
  length = 0;
  listData = NULL;
}
template<class ItemType>
bool SortedType<ItemType>::IsFull() const
// Returns true if there is no room for another ItemType 
//  on the free store; false otherwise.
{
  NodeType<ItemType>* location;
  try
  {
    location = new NodeType<ItemType>;
    delete location;
    return false;
  }
  catch(bad_alloc exception)
  {
    return true;
  }
}
template <class ItemType>
int SortedType<ItemType>::LengthIs() const
// Post: Number of items in the list is returned.
{
  return length;
}
template <class ItemType>
void SortedType<ItemType>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
    NodeType<ItemType>* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}
template <class ItemType>
void SortedType<ItemType>::RetrieveItem(ItemType& item, 
     bool& found)
{
  bool moreToSearch;
  NodeType<ItemType>* location;

  location = listData;
  found = false;
  moreToSearch = (location != NULL);

  while (moreToSearch && !found)
  {
    if (location->info < item)
    {
      location = location->next;
      moreToSearch = (location != NULL);
    }
    else if (item == location->info)
    {
      found = true;
      item = location->info;
    }
    else
      moreToSearch = false;
  }
}

template <class ItemType>
void SortedType<ItemType>::InsertItem(ItemType item)
{
  NodeType<ItemType>* newNode;  // pointer to node being inserted
  NodeType<ItemType>* predLoc;  // trailing pointer
  NodeType<ItemType>* location; // traveling pointer
  bool moreToSearch;

  location = listData;
  predLoc = NULL;
  moreToSearch = (location != NULL);

  // Find insertion point.
  while (moreToSearch)
  {
    if (location->info > item) //부등호 방향 바꾸어서 내림차순으로 변경
    {
      predLoc = location;
      location = location->next;
      moreToSearch = (location != NULL);
    }
    else
      moreToSearch = false;
  }

  // Prepare node for insertion
  newNode = new NodeType<ItemType>;
  newNode->info = item;
  // Insert node into list.
  if (predLoc == NULL)         // Insert as first
  {
    newNode->next = listData;
    listData = newNode;
  }
  else
  {
    newNode->next = location;
    predLoc->next = newNode;
  }
  length++;
}

template <class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
    NodeType<ItemType>* location = listData;
    NodeType<ItemType>* tempLocation;

    // Locate node to be deleted.
    if (item == listData->info)
    {
        tempLocation = location;
        listData = listData->next;		// Delete first node.
    }
    else
    {
        while (!(item==(location->next)->info))
          location = location->next;

        // Delete node at location->next
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
}
template <class ItemType>

void SortedType<ItemType>::ResetList()
// Post: Current position has been initialized.
{
  currentPos = NULL;
}
 
template <class ItemType>
void SortedType<ItemType>::GetNextItem(ItemType& item)
// Post:  Current position has been updated; item is 
//        current item.
{
  if (currentPos == NULL)
    currentPos = listData;
  item = currentPos->info; 
  currentPos = currentPos->next;

} 

template <class ItemType>
SortedType<ItemType>::~SortedType()
// Post: List is empty; all items have been deallocated.
{
    NodeType<ItemType>* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
  }
