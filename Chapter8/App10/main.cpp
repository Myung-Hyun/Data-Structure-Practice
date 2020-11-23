#include <iostream>
#include "TreeType.h"
using namespace std;


int main() {

	TreeType tree;

	int node_num = 0;
	int num = 0;

	cin >> node_num;
	for (int i = 0; i < node_num; i++) {
		cin >> num;
		tree.InsertItem(num);
	}

	int node1 = 0;
	int node2 = 0;

	cin >> node1 >> node2;

	QueType ancestors1, ancestors2;

	tree.Anscestors(node1,ancestors1); //할당 해버리면 shallow copy가 된다. 그래서 구현된 copy constructor(deep copy) 사용.
	tree.Anscestors(node2,ancestors2);
	
	

	ItemType ancestor1=0, ancestor2=0;
	ItemType solution=0;

	
	while (ancestor1 == ancestor2 && !ancestors1.IsEmpty() && !ancestors2.IsEmpty()) //두 값이 다르거나 ancestors1이 비었거나 ancestors2가 비었을 때 그만둔다.
	//그만두는 조건을 쓰고 드모르간 쓰면 while문 조건을 얻을 수 있다. 
	{
		ancestors1.Dequeue(ancestor1);
		ancestors2.Dequeue(ancestor2);
		solution = ancestor1;
	}
	
	cout << solution;
	
	return 0;
}
