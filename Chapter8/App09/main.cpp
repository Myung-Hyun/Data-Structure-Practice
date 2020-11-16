#include "TreeType.h"

int main() {
	TreeType tree;

	// Input N, parents, Delete No.
	int N; cin >> N;
	int* parents = new int[N];
	for (int i = 0; i < N; i++)
		cin >> parents[i];
	int delNodeNo; cin >> delNodeNo;

	// Make Tree
	for (int idx = 0; idx < N; idx++)
		tree.InsertItem(parents[idx], idx);
	
	// Del
	tree.DeleteItem(delNodeNo);
	
	// Count leaf node
	cout << tree.LeafCount() << endl;
	return 0;
}
