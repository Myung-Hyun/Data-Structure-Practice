#include <iostream>
using namespace std;

template <class ItemType>
void Swap(ItemType& one, ItemType& two);

template<class ItemType>
// Assumes ItemType is either a built-in simple type or a class
// with overloaded relational operators.
struct HeapType
{
  void ReheapDown(int root, int bottom);
  void ReheapUp(int root, int bottom);

  void ReheapUp2(int root, int bottom);
  void ReheapDown2(int root, int bottom);
  void Print();

  ItemType* elements;   // Array to be allocated dynamically
  int numElements;
};

/*
template<class ItemType>
void HeapType<ItemType>::Print()
{
    for (int i = 0;i < numElements;i++)
        cout << elements[i];
}*/

template <class ItemType>
void Swap(ItemType& one, ItemType& two)
{
  ItemType temp;
  temp = one;
  one = two;
  two = temp;
}  

template<class ItemType>
void HeapType<ItemType>::ReheapUp(int root, int bottom)
// Post: Heap property is restored.
{
  int parent;
  
  if (bottom > root)
  {
    parent = (bottom-1) / 2;
    if (elements[parent] < elements[bottom])
    {
      Swap(elements[parent], elements[bottom]);
      ReheapUp(root, parent);
    }
  }
}
template<class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom)
// Post: Heap property is restored.
{
  int maxChild;
  int rightChild;
  int leftChild;

  leftChild = root*2+1;
  rightChild = root*2+2;
  if (leftChild <= bottom)
  {
    if (leftChild == bottom)
      maxChild = leftChild;
    else
    {
      if (elements[leftChild] <= elements[rightChild])
        maxChild = rightChild;
      else
        maxChild = leftChild;
    }
    if (elements[root] < elements[maxChild])
    {
      Swap(elements[root], elements[maxChild]);
      ReheapDown(maxChild, bottom);
    }
  }
}

template<class ItemType>
void HeapType<ItemType>::ReheapUp2(int root, int bottom)
// bottom은 새로 삽입된 노드로 제일 아래 레벨의 제일 오른쪽 노드를 가리킴
{
    int parent;
    bool reheaped = false; // bottom이 제 위치를 찾아가서 reheap이 되면 true

    while (bottom > root && !reheaped)
    {
        parent = (bottom-1)/2; // bottom 값으로부터 부모 노드의 위치 계산

        if (elements[parent] < elements[bottom])
        {
            Swap(elements[parent], elements[bottom]);// bottom을 부모 노드와 값 교환 
            bottom=parent;  // bottom이 이제 부모 노드의 위치를 가리킴
        }
        else
        {
            reheaped = true;
        }
    }
}

template<class ItemType>
void HeapType<ItemType>::ReheapDown2(int root, int bottom)
// root 노드를 제외하고 나머지 노드들은 heap의 조건을 만족하고 있음
{
    int maxChild, leftChild, rightChild; //maxChild, leftChild rightChild는 배열 인덱스
    bool reheaped = false; // root가 제 위치를 찾아가 reheap이 되면 True

    leftChild = root*2+1; // root 값으로부터 왼쪽 자식노드의 위치 계산 

    while (leftChild <= bottom && !reheaped)
    {
        //maxChild를 찾아준다.
        if (leftChild == bottom) // 왼쪽 자식 노드 하나만 있는 경우
            maxChild = leftChild;
        else {
            rightChild = root * 2 + 2;
            maxChild = (elements[leftChild] <= elements[rightChild]) ? rightChild : leftChild;
        }

        if (elements[root] < elements[maxChild]) {
            Swap(elements[root], elements[maxChild]);
            root = maxChild; // maxChild 가 root의 새로운 위치가 됨
            leftChild = root * 2 + 1;
        }
        else
            reheaped = true;
    }
}
