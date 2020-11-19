#include <iostream>
#include "TreeType.h"

using namespace std;

struct TreeNode
{
  ItemType info;
  TreeNode* left;
  TreeNode* right;
};

bool TreeType::IsFull() const
// Returns true if there is no room for another item 
//  on the free store; false otherwise.
{
  TreeNode* location;
  try
  {
    location = new TreeNode;
    delete location;
    return false;
  }
  catch(std::bad_alloc exception)
  {
    return true;
  }
}

bool TreeType::IsEmpty() const
// Returns true if the tree is empty; false otherwise.
{
  return root == NULL;
}

int CountNodes(TreeNode* tree);

int TreeType::LengthIs() const
// Calls recursive function CountNodes to count the 
// nodes in the tree.
{
  return CountNodes(root);
}


int CountNodes(TreeNode* tree)
// Post: returns the number of nodes in the tree.
{
  if (tree == NULL)
    return 0;
  else 
    return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}

void Retrieve(TreeNode* tree, 
     ItemType& item, bool& found);

void TreeType::RetrieveItem(ItemType& item, bool& found)
// Calls recursive function Retrieve to search the tree for item.
{
  Retrieve(root, item, found);
}


void Retrieve(TreeNode* tree, 
     ItemType& item, bool& found)
// Recursively searches tree for item.
// Post: If there is an element someItem whose key matches item's,
//       found is true and item is set to a copy of someItem; 
//       otherwise found is false and item is unchanged.
{
  if (tree == NULL)
    found = false;                     // item is not found.
  else if (item < tree->info)      
    Retrieve(tree->left, item, found); // Search left subtree.
  else if (item > tree->info)
    Retrieve(tree->right, item, found);// Search right subtree.
  else
  {
    item = tree->info;                 // item is found.
    found = true;
   }
} 

void Insert(TreeNode*& tree, ItemType item);

void TreeType::InsertItem(ItemType item)
// Calls recursive function Insert to insert item into tree.
{
  Insert(root, item);
}


void Insert(TreeNode*& tree, ItemType item)
// Inserts item into tree.
// Post:  item is in tree; search property is maintained.
{
  if (tree == NULL)
  {// Insertion place found.
    tree = new TreeNode;
    tree->right = NULL;
    tree->left = NULL;
    tree->info = item;
  }
  else if (item < tree->info)
    Insert(tree->left, item);    // Insert in left subtree.
  else
    Insert(tree->right, item);   // Insert in right subtree.
} 
void DeleteNode(TreeNode*& tree);

void Delete(TreeNode*& tree, ItemType item);

void TreeType::DeleteItem(ItemType item)
// Calls recursive function Delete to delete item from tree.
{
  Delete(root, item);
}


void Delete(TreeNode*& tree, ItemType item)
// Deletes item from tree.
// Post:  item is not in tree.
{
  if (item < tree->info)
    Delete(tree->left, item);   // Look in left subtree.
  else if (item > tree->info)
    Delete(tree->right, item);  // Look in right subtree.
  else
    DeleteNode(tree);           // Node found; call DeleteNode.
}   

void GetPredecessor(TreeNode* tree, ItemType& data);

void DeleteNode(TreeNode*& tree)
// Deletes the node pointed to by tree.
// Post: The user's data in the node pointed to by tree is no 
//       longer in the tree.  If tree is a leaf node or has only 
//       non-NULL child pointer the node pointed to by tree is 
//       deleted; otherwise, the user's data is replaced by its 
//       logical predecessor and the predecessor's node is deleted.
{
  ItemType data;
  TreeNode* tempPtr;

  tempPtr = tree;
  if (tree->left == NULL)
  {
    tree = tree->right;
    delete tempPtr;
  }
  else if (tree->right == NULL)
  {
    tree = tree->left;
    delete tempPtr;
  }
  else
  {
    GetPredecessor(tree->left, data);
    tree->info = data;
    Delete(tree->left, data);  // Delete predecessor node.
  }
}

void GetPredecessor(TreeNode* tree, ItemType& data)
// Sets data to the info member of the right-most node in tree.
{
  while (tree->right != NULL)
    tree = tree->right;
  data = tree->info;
}

void PrintTree(TreeNode* tree, std::ofstream& outFile) 
// Prints info member of items in tree in sorted order on outFile.
{
  if (tree != NULL)
  {
    PrintTree(tree->left, outFile);   // Print left subtree.
    outFile << tree->info;
    PrintTree(tree->right, outFile);  // Print right subtree.
  }
}

void TreeType::Print(std::ofstream& outFile) const
// Calls recursive function Print to print items in the tree.
{
  PrintTree(root, outFile);
}

TreeType::TreeType()
{
  root = NULL;
}

void Destroy(TreeNode*& tree);

TreeType::~TreeType()
// Calls recursive function Destroy to destroy the tree.
{
  Destroy(root);
}


void Destroy(TreeNode*& tree)
// Post: tree is empty; nodes have been deallocated.
{
  if (tree != NULL)
  {
    Destroy(tree->left);
    Destroy(tree->right);
    delete tree;
  }
}

void TreeType::MakeEmpty()
{
  Destroy(root);
  root = NULL;
}


void CopyTree(TreeNode*& copy, 
     const TreeNode* originalTree);

TreeType::TreeType(const TreeType& originalTree)
// Calls recursive function CopyTree to copy originalTree 
//  into root.
{
  CopyTree(root, originalTree.root);
}

void TreeType::operator= 
     (const TreeType& originalTree)
// Calls recursive function CopyTree to copy originalTree 
// into root.
{
  {
  if (&originalTree == this)
    return;             // Ignore assigning self to self
  Destroy(root);      // Deallocate existing tree nodes
  CopyTree(root, originalTree.root);
  }

}
void CopyTree(TreeNode*& copy, 
     const TreeNode* originalTree)
// Post: copy is the root of a tree that is a duplicate 
//       of originalTree.
{
  if (originalTree == NULL)
    copy = NULL;
  else
  {
    copy = new TreeNode;
    copy->info = originalTree->info;
    CopyTree(copy->left, originalTree->left);
    CopyTree(copy->right, originalTree->right);
  }
}
// Function prototypes for auxiliary functions.

void PreOrder(TreeNode*, QueType&);
// Enqueues tree items in preorder.


void InOrder(TreeNode*, QueType&);
// Enqueues tree items in inorder.


void PostOrder(TreeNode*, QueType&);
// Enqueues tree items in postorder.


void TreeType::ResetTree(OrderType order)
// Calls function to create a queue of the tree elements in 
// the desired order.
{
  switch (order)
  {
    case PRE_ORDER : PreOrder(root, preQue);
                     break;
    case IN_ORDER  : InOrder(root, inQue);
                     break;
    case POST_ORDER: PostOrder(root, postQue);
                     break;
  }
}


void PreOrder(TreeNode* tree, 
     QueType& preQue)
// Post: preQue contains the tree items in preorder.
{
  if (tree != NULL)
  {
    preQue.Enqueue(tree->info);
    PreOrder(tree->left, preQue);
    PreOrder(tree->right, preQue);
  }
}


void InOrder(TreeNode* tree, 
     QueType& inQue)
// Post: inQue contains the tree items in inorder.
{
  if (tree != NULL)
  {
    InOrder(tree->left, inQue);
    inQue.Enqueue(tree->info);
    InOrder(tree->right, inQue);
  }
}


void PostOrder(TreeNode* tree, 
     QueType& postQue)
// Post: postQue contains the tree items in postorder.
{
  if (tree != NULL)
  {
    PostOrder(tree->left, postQue);
    PostOrder(tree->right, postQue);
    postQue.Enqueue(tree->info);
  }
}


void TreeType::GetNextItem(ItemType& item, 
     OrderType order, bool& finished)
// Returns the next item in the desired order.
// Post: For the desired order, item is the next item in the queue.
//       If item is the last one in the queue, finished is true; 
//       otherwise finished is false.
{
  finished = false;
  switch (order)
  {
    case PRE_ORDER  : preQue.Dequeue(item);
                      if (preQue.IsEmpty())
                        finished = true;
                      break;
    case IN_ORDER   : inQue.Dequeue(item);
                      if (inQue.IsEmpty())
                        finished = true;
                      break;
    case  POST_ORDER: postQue.Dequeue(item);
                      if (postQue.IsEmpty())
                        finished = true;
                      break;
  }
}


//입력 받은 값을 만날 때까지 노드를 따라가면서 내용을 출력해준다.

void TreeType::Ancestors(ItemType value)
{
    bool found = false;
    QueType path;

    TreeNode* currentNode = root;

    while (currentNode!=NULL)  // value를 가진 노드를 찾거나 트리 끝에 도달할 때까지
    {
        if (currentNode->info == value)  // value를 가진 노드를 찾으면
        {
            found = true;
            break;
        }
        else {
            path.Enqueue(currentNode->info); // path에 현재 노드의 값을 삽입
            if (currentNode->info > value)
                currentNode=currentNode->left; // 왼쪽 서브트리로 이동
            else
                currentNode = currentNode->right; // 오른쪽 서브트리로 이동
        }
    }

    if (found)
    {
        ItemType item;
        while (!path.IsEmpty())
        {
            path.Dequeue(item);
            cout << item << " ";
        }
    }   // path에 있는 내용을 출력
    else
    {
        cout << "Can't find value in tree";
    }
        // value를 찾을 수 없다고 출력
}

bool Ancestors_recursive(TreeNode* tree, ItemType item);

bool Ancestors_recursive(TreeNode* tree, ItemType item)
{
    bool found = false;
    if (tree == NULL)
        return false;

    if (tree->info ==item) // value를 찾은 경우
        return true;

    if (tree->info > item)
        found = Ancestors_recursive(tree->left, item); // 왼쪽 서브트리 호출
    else
        found = Ancestors_recursive(tree->right, item); // 오른쪽 서브트리 호출

    if (found) // 재귀호출 후 value값을 찾았으면
        cout << tree->info;// 현재 노드의 값을 출력

    return found;
}

void TreeType::Ancestors_re(ItemType value)
{
    Ancestors_recursive(root, value);
}


//트리로부터 아이템을 순차적으로 얻으면서 그 값의 개수를 카운트 한다.
//주어진 value보다 큰 아이템을 얻을 경우 즉시 루프를 벋어나도록 한다.
int Smaller(TreeType tree, int value)
{
    ItemType item;
    bool finished = false;
    int count = 0;

    tree.ResetTree(IN_ORDER);

    do {
        tree.GetNextItem(item,IN_ORDER ,finished );

        if (item<value)
            count++;
        else
            finished = true;
    } while (!finished);

    return count;
}


//리스트가 가지는 아이템을 배열로 옮긴 뒤, 배열에서 입력 순서를 계산하여 트리에 입력한다. 
void AddElement(TreeType& tree, int Array[], int from, int to);
void MakeTree(TreeType& tree, SortedType<int>& list);

void MakeTree(TreeType& tree, SortedType<int>& list)
{

    int length = list.LengthIs();  //리스트 크기를 얻는다
    int* array = new int[length];  //동적 배열 할당
    int item_info;
    int i;

    list.ResetList();

    for (i = 0; i < length; i++)
    {
        list.GetNextItem(item_info);
        array[i] = item_info;
    }

    AddElement(tree, array, 0, length - 1);

    delete[] array;  // 동적 배열 삭제
}
void AddElement(TreeType& tree, int Array[], int front, int rear)
{
    int mid;			//중간 값을 기록하는 변수
    if (front<=rear) {		//함수의 종료조건
        mid = (front+rear)/2 ; 							
        tree.InsertItem(Array[mid]);
        AddElement(tree, Array, front, mid-1);
        AddElement(tree, Array, mid+1, rear);
    }
}



bool MatchingItem_Unsorted(TreeType& tree, UnsortedType<ItemType>& list)
{
    int list_length = list.LengthIs();
    int tree_length = tree.LengthIs();

    if (list_length != tree_length) //길이를 먼저 비교, 같은지 검사한다.
    {
        return false;
    }
    else
    {
        ItemType item;
        bool found;

        list.ResetList(); //list에 iterator를 사용할 준비를 한다
        for (int i = 0; i < list_length; i++) {
            list.GetNextItem(item); // list에서 하나의 아이템을 가져온다
            tree.RetrieveItem(item, found); //트리에 해당 아이템이 있는지 검색. O(logN)이 걸림.
            if (!found)
            {
                return false;
            }
        }
        return true;
    }
}
//아래 구현과 비교해 볼 때 수행시간 면에서 무슨 차이가 있을까? 
/*
tree.ResetTree(IN_ORDER); // tree에 iterator를 사용할 준비를 한다

for (int i = 0; i < list_length; i++) {
    tree.GetNextItem(item, IN_ORDER, found); // tree에서 하나의 아이템을 가져온다
    list.RetrieveItem(item, found); // list에 해당 아이템이 있는 검색. O(N)이 걸림.
    if (!found));
}*/


