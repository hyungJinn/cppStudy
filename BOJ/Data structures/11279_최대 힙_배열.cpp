#include <iostream>
#include <algorithm>

#define endl '\n'
#define MAX 100010 //¿Ö 100010ÀÌÁö??

using namespace std;

int N, heap_idx;
int heap_array[MAX];

void Heap_push(int data) {
	int idx = ++heap_idx;
	heap_array[idx] = data;

	while ((idx != 1) && (heap_array[idx] > heap_array[idx / 2])) {
		swap(heap_array[idx], heap_array[idx / 2]);
		idx = idx / 2;
	}
}

int Heap_pop() {
	if (heap_idx == 0) return 0;
	int result = heap_array[1];
	heap_array[1] = heap_array[heap_idx--];

	int parent = 1;
	int child;
	while (1) {
		child = parent * 2;
		if (child + 1 <= heap_idx && heap_array[child] < heap_array[child + 1]) child++;
		if (child > heap_idx || heap_array[child] < heap_array[parent]) break;
		swap(heap_array[child], heap_array[parent]);
		parent = child;
	}
	return result;
}

void Solution() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		if (x == 0) cout << Heap_pop() << endl;
		else Heap_push(x);
	}
}

void Solve() {
	Solution();
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}