//I referred to this site, https://jackpot53.tistory.com/33.

#include <iostream>
#include <algorithm>
#include <vector>

#define endl '\n'

using namespace std;

int N, M;
vector<int> nVector;
vector<int> mVector;

int lowerBound(vector<int> &v, int value) {
	int low = 0;
	int high = v.size();
	//int high = v.size() - 1;
	while (low < high) {
		int mid = low + (high - low) / 2;
		if (value <= v[mid]) {
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}
	return low;
}

int upperBound(vector<int> &v, int value) {
	int low = 0;
	int high = v.size();
	//int high = v.size() - 1;
	while (low < high) {
		int mid = low + (high - low) / 2;
		if (value >= v[mid]) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}
	return low;
}

void input() {
	cin >> N;
	int X;
	for (int i = 0; i < N; i++) {
		cin >> X;
		nVector.push_back(X);
	}
	//nVector.push_back(10000001); //Exception Handling

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> X;
		mVector.push_back(X);
	}
}

void solution() {
	sort(nVector.begin(), nVector.end());

	int num;
	for (int i = 0; i < M; i++) {
		num = (upperBound(nVector, mVector[i]) - lowerBound(nVector, mVector[i]));
		cout << num << " ";
	}
	cout << endl;
}

void solve() {
	input();
	solution();
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	solve();

	return 0;
}
