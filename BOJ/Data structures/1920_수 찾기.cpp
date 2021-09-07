#include <iostream>
#include <algorithm>
#include <vector>

#define endl '\n'

using namespace std;

int N, M;
vector<int> nVector;
vector<int> mVector;

int binarySearch(vector<int>& v, int value) {
	int low = 0;
	int high = v.size() - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (value > v[mid]) low = mid + 1;
		else if (value < v[mid]) high = mid - 1;
		else return mid;
	}
	return -(low + 1);
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int X;
		cin >> X;
		nVector.push_back(X);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int X;
		cin >> X;
		mVector.push_back(X);
	}
}

void solution() {
	sort(nVector.begin(), nVector.end());

	for (int i = 0; i < M; i++) {
		//cout << binarySearch(nVector, mVector[i]);
		if (binarySearch(nVector, mVector[i]) >= 0) cout << "1";
		else cout << "0";
		cout << endl;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	solution();

	return 0;
}