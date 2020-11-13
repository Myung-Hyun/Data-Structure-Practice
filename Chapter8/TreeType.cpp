
#include "TreeType.h"
struct TreeNode
{
  ItemType info;
  TreeNode* left;
  TreeNode* right;
};

TreeNode* PtrToSuccessor(TreeNode*& tree);

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
      tree=PtrToSuccessor(tree->right);
      tree->right = tempPtr->right;
      delete tempPtr;
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

// Recursive version:
TreeNode* TreeType::PtrToSuccessor(TreeNode*& tree)  // 파라메터 타입: (1) TreeNode* or (2) TreeNode*&
{
    if (tree->left != NULL) //왼쪽 노드가 NULL이 아니면
        return PtrToSuccessor(tree->left); // general case
    else {	// base case
        TreeNode* tempPtr = tree; // tree 값을 backup
        // tree가 tree의 right child를 가리키도록 수정

        //right child가 null인 경우 자연스럽게 case1을 만족
        if (tempPtr->right == NULL)
        {
            tree = NULL;
        }
        else
        {
            tree = tempPtr->right;
        }
        return tempPtr;
        // tempPtr을 리턴
    }
}

// Nonrecursive version:
TreeNode* TreeType::PtrToSuccessor2(TreeNode*& tree)  
{
    while (tree->left->left !=NULL) // 제일 왼쪽 노드까지 내려간다
        tree = tree->left;

    TreeNode* tempPtr = tree->left; // tree 값을 backup
    tree->left = tree->left->right; // tree가 tree의 right child를 가리키도록 수정

    return tempPtr;// tempPtr을 리턴
}

TreeNode* PtrToSuccessor(TreeNode*& tree)  //멤버함수 아니도록 만든다.
{
    if (tree->left != NULL) //왼쪽 노드가 NULL이 아니면
        return PtrToSuccessor(tree->left); // general case
    else {	// base case
        TreeNode* tempPtr = tree; // tree 값을 backup
        // tree가 tree의 right child를 가리키도록 수정

        //right child가 null인 경우 자연스럽게 case1을 만족
        if (tempPtr->right == NULL)
        {
            tree = NULL;
        }
        else
        {
            tree = tempPtr->right;
        }
        return tempPtr;
        // tempPtr을 리턴
    }
}


// 노드를 재귀적으로 검사하면서 노드가 가지고 있는 값을 비교하여 이진 검색 트리인지 아닌지 검사한다. 
bool Imp_IsBST(TreeNode* tree);

bool TreeType::IsBST() // 클래스에 IsBST 함수를 선언하세요.
{
    ItemType min, max;
    return Imp_IsBST(root, min, max);
}

bool Imp_IsBST(TreeNode* tree, ItemType& min, ItemType& max) // min, max: returns the value range of the tree
{
    bool isBST;

    if (tree = NULL) return true; // emptry tree는 BST

    //왼쪽 노드가 NULL이 아니면, 왼쪽 서브트리가 BST인지 체크하고 tree->info와 비교
    if(tree->left !=NULL) {
        
        isBST = Imp_IsBST(tree->left, min, max);
        // 왼쪽 서브트리가 BST가 아니거나 tree->info가 왼쪽 서브트리 값보다 작은 경우
        if (!isBST || tree->info <= left_max) return false;
    }
    //오른쪽 노드가 NULL이 아니면, 오른쪽 서브트리가 BST인지 체크하고 tree->info와 비교
    if (tree->right !=NULL) {
        
        isBST = Imp_IsBST(tree->left, min, max);
        if (!isBST || tree->info >= right_min) return false;
    }

    min = (tree->left == NULL) ? tree->info : min;      
    max = (tree->right == NULL) ? tree->info : max;
    return true;
}


int Imp_LeafCount(TreeNode* tree);
int TreeType::LeafCount()
{
    return Imp_LeafCount(root);
}

int Imp_LeafCount(TreeNode* tree)
{
    if (tree == NULL) //리프 노드가 아닐 경우.
        return 0;
    else if (tree->left == NULL && tree->right == NULL) //노드의 좌우가 NULL일 경우
        return 1;
    else
        return Imp_LeafCount(tree->left) + Imp_LeafCount(tree->right);
        //노드의 좌우를 재귀 호출하여 더한다.
}

int Imp_SingleParentCount(TreeNode* tree);

int TreeType::SingleParentCount()
{
    return Imp_SingleParentCount(root);
}

int Imp_SingleParentCount(TreeNode* tree)
{
    if (tree == NULL)
        return 0;//0을 리턴.
    else if (tree->left == NULL && tree->right != NULL)
        return Imp_SingleParentCount(tree->right) + 1;//1개의 노드를 가지므로 오른쪽 노드를 재귀 호출하고 1을 더하여 리턴.
    else if (tree->right == NULL && tree->left != NULL)
        return Imp_SingleParentCount(tree->left) + 1;//1개의 노드를 가지므로 왼쪽 노드를 재귀 호출하고 1을 더하여 리턴.
    else
        return Imp_SingleParentCount(tree->left) + Imp_SingleParentCount(tree->right);//노드의 양쪽을 재귀 호출하여 더한다.
}
