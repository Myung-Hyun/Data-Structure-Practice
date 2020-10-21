// Header file for Unsorted List ADT.  


template <class ItemType>
struct NodeType;


// Assumption:  ItemType is a type for which the operators "<" 
// and "==" are defined?ither an appropriate built-in type or
// a class that overloads these operators.

template <class ItemType>
class UnsortedType
{
public:
  UnsortedType();     // Class constructor	
  ~UnsortedType();    // Class destructor

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

  void DeleteItem_a(ItemType item);
  void DeleteItem_b(ItemType item);

  void ResetList();
  // Initializes current position for an iteration through the
  // list.
  // Post: Current position is prior to list.

  void GetNextItem(ItemType& item);
  // Gets the next element in list.
  // Pre:  Current position is defined.
  //       Element at current position is not last in list.
  // Post: Current position is updated to next position.
  //       item is a copy of element at current position.

  void MergeLists(UnsortedType<ItemType>& other, UnsortedType<ItemType>& result);

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
UnsortedType<ItemType>::UnsortedType()  // Class constructor
{
  length = 0;
  listData = NULL;
}

template <class ItemType>
UnsortedType<ItemType>::~UnsortedType()
// Class destructor
{
  MakeEmpty();
}  
template<class ItemType>
bool UnsortedType<ItemType>::IsFull() const
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
int UnsortedType<ItemType>::LengthIs() const
// Post: Number of items in the list is returned.
{
  return length;
}
template <class ItemType>
void UnsortedType<ItemType>::MakeEmpty()
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
void UnsortedType<ItemType>::RetrieveItem(ItemType& item, 
    bool& found)
// Pre:  Key member(s) of item is initialized.
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been stored in item;
//       otherwise, item is unchanged. 
{
    bool moreToSearch;
    NodeType<ItemType>* location;

    location = listData;
    found = false;
    moreToSearch = (location != NULL);

    while (moreToSearch && !found)
    {
        if (item == location->info)
        {
            found = true;
            item = location->info;
        }
        else
        {
            location = location->next;
            moreToSearch = (location != NULL);
        }
    }
}
template <class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType item)
// item is in the list; length has been incremented.
{
    NodeType<ItemType>* location;

    location = new NodeType<ItemType>;
    location->info = item;
    location->next = listData;
    listData = location;
    length++;
}
template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item)
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
void UnsortedType<ItemType>::DeleteItem_a(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
    NodeType<ItemType>* location = listData;
    NodeType<ItemType>* preLoc = NULL;
    NodeType<ItemType>* tempLocation;

    // Locate node to be deleted.
    if (item == listData->info)
    {
        tempLocation = location;
        listData = listData->next;		// Delete first node.
    }
    else
    {
        preLoc = location;
        location = location->next;
        
        while (!(item == location->info)) //찾지 못했고 NULL아니면 계속 찾는다. 
        {
            preLoc = location;
            location = location->next;
            if (location == NULL) //while문 조건에 같이 쓰면 location이 NULL일 때, location->info를 실행해버려서 에러남.
                break;
        }
        
        tempLocation = location;
        if (location != NULL)
        {
            preLoc->next = location->next;
        }
    }

    if (location != NULL)
    {
        delete tempLocation;
    }
    length--;
}

template <class ItemType>
void UnsortedType<ItemType>::DeleteItem_b(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{

    NodeType<ItemType>* location = listData;
    NodeType<ItemType>* preLoc = NULL;
    NodeType<ItemType>* tempLocation;
    bool finish=false;

    // Locate node to be deleted.
    if (item == listData->info)
    {
        tempLocation = location;
        listData = listData->next;		// Delete first node.
        delete tempLocation;
    }
    else
    {
        preLoc = location;
        location = location->next;
        while (finish != true)
        {
           
            while (item != location->info) //찾지 못했고 NULL아니면 계속 찾는다. 
            {
                preLoc = location;
                location = location->next;
                if (location == NULL) //while문 조건에 같이 쓰면 location이 NULL일 때, location->info를 실행해버려서 에러남.
                {
                    finish = true;
                    break;
                }
                
            }

            tempLocation = location;
            if (location != NULL)
            {
                preLoc->next = location->next;
                location = location->next; //모든 원소를 지우기 위울 때, 다음번 검색을 위해 추가해주어야 하는 코드, 하지 않으면 location이 NULL이 된다. 
                delete tempLocation;
            }
        }
    }
    length--;
}
template <class ItemType>
void UnsortedType<ItemType>::ResetList()
// Post: Current position has been initialized.
{
  currentPos = NULL;
}
 
template <class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType& item)
// Post:  Current position has been updated; item is current item.
{
  if (currentPos == NULL)
    currentPos = listData;
  else
    currentPos = currentPos->next;
  item = currentPos->info;
} 

//(수정할 부분)Unsorted list의 경우 listData 쪽으로 계속 넣어주어도 되므로, 처음 넣는 경우(if)문 필요없고, location으로 계속 마지막 요소 가리킬 필요도 없다.
template <class ItemType>
void UnsortedType<ItemType>::MergeLists(UnsortedType<ItemType>& other, UnsortedType<ItemType>& result)
{
    NodeType<ItemType>* ptr1 = listData;
    NodeType<ItemType>* ptr2 = other.listData;

    NodeType<ItemType>* location = result.listData; //result 끝에 계속 넣기 위한 포인터



    while (ptr1 != NULL)
    {
        NodeType<ItemType>* temp = new NodeType<ItemType>; // while문 돌때마다 할당받아서 result의 크기를 늘린다.
        temp->info = ptr1->info;
        if (location == NULL)
        {
            result.listData = temp;
            location = temp;
        }
        else
        {
            location->next = temp; //마지막에 새로운 메모리 연결
            location = temp; //마지막 위치 가리키기
        }
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL)
    {
        NodeType<ItemType>* temp = new NodeType<ItemType>; 
        temp->info = ptr2->info;
       
        location->next = temp; //마지막에 새로운 메모리 연결
        location = temp; //마지막 위치 가리키기
        
        ptr2 = ptr2->next;

    }
    location->next = NULL; //이 코드 없으면 소멸자 에러난다. NodeType 의 next가 NULL 초기화 되어 있지 않아서, 마지막 node의 next는 NULL로 해줘야 한다.
}
