#include <iostream>
#include <vector>
#include <queue>

#define endl '\n'

using namespace std;

int N, K;
vector<int> v;
queue<int> result;

void input() {
	cin >> N >> K;
	for (int i = 0; i <= N; i++) v.push_back(i);
}

void solution() {
	int num = K;
	result.push(num);
	v[num] = 0;

	while (result.size() < N) {
		int count = 0;
		while (count < K) {
			num = (num == N) ? 1 : num + 1;
			if (v[num] != 0) count += 1;
		}
		result.push(num);
		v[num] = 0;
	}
		
}

void solve() {
	input();
	solution();

	cout << "<";
	for (int i = 0; i < N; i++) {
		if (i == N - 1) {
			cout << result.front();
		}
		else {
			cout << result.front() << ", ";
		}
		result.pop();
	}
	cout << ">" << endl;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	solve();

	return 0;
}