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

  void MergeLists(SortedType<ItemType>& other, SortedType<ItemType>& result);

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
  catch(std::bad_alloc exception)
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
    if (location->info < item)
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


template <class ItemType>
void SortedType<ItemType>::MergeLists(SortedType<ItemType>& other, SortedType<ItemType>& result)
{
    NodeType<ItemType>* ptr1 = listData;
    NodeType<ItemType>* ptr2 = other.listData;
    
    NodeType<ItemType>* location = result.listData; //result 끝에 계속 넣기 위한 포인터
    
    

    while (ptr1 != NULL && ptr2 != NULL)
    {
        NodeType<ItemType>* temp = new NodeType<ItemType>; // while문 돌때마다 할당받아서 result의 크기를 늘린다.
        if (ptr1->info < ptr2->info) //ptr1의 값을 result에
        {
            temp->info = ptr1->info;
            if (location == NULL) //result에 처음 넣는 경우
            {
                result.listData = temp;
                location = temp;
            }
            else
            {
                location->next = temp; //마지막에 새로운 메모리 연결
                location = temp; //마지막 위치 가리키기
            }
            ptr1 = ptr1->next; //list1의 다음 요소를 가리키게 하고 다시 비교.
        }
        else
        {
            temp->info = ptr2->info;
            if (location == NULL)
            {
                result.listData = temp;
                location = temp;
            }
            else
            {
                location->next = temp;
                location = temp;
            }
            ptr2 = ptr2->next;
        }
    }
    //길이가 다른 경우 나머지를 넣어줘야 함. 
    //남았다는 것은 먼저 들어간 요소보다 다 큰 것이고 이미 정렬되어 있으므로, 크기 비교 필요 없음.
    
    if (ptr1 == NULL)
    {
        while (ptr2 != NULL)
        {
            NodeType<ItemType>* temp = new NodeType<ItemType>; 
            temp->info = ptr2->info;
            location->next = temp;
            location = temp;
            ptr2 = ptr2->next; //while문 조건을 바꾸는 코드가 while문 안에 있어야 while문이 더 안돈다.
        }
        
    }

    if (ptr2 == NULL)
    {
        while (ptr1 != NULL)
        {
            NodeType<ItemType>* temp = new NodeType<ItemType>;
            temp->info = ptr1->info;
            location->next = temp;
            location = temp;
            ptr1 = ptr1->next;
        }
    }
    
    location->next = NULL; //이 코드 없으면 소멸자 에러난다. NodeType 의 next가 NULL 초기화 되어 있지 않아서, 마지막 node의 next는 NULL로 해줘야 한다.
}
