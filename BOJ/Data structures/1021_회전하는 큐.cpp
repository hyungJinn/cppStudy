#include <iostream>
#include <deque>
#include <vector>

#define endl '\n'

using namespace std;

int N, M, cnt;

deque<int> D;
vector<int> V;

void Input() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;
		V.push_back(x - 1);
	}

	for (int i = 0; i < N; i++) {
		D.push_back(i);
	}
}

void Solution() {
	int idx, left, right, target;
	idx = left = right = target = 0;

	while (idx < M) {
		if (V[idx] == D.front()) {
			D.pop_front();
			++idx;
		}
		else {
			for (int i = 0; i < D.size(); i++) {
				if (V[idx]  == D[i]) {
					target = i;
				}
			}

			left = target;
			right = D.size() - target; //(D.size() - 1) - target + 1

			if (left < right) {
				for (int i = 0; i < left; i++) {
					D.push_back(D.front());
					D.pop_front();
					cnt++;
				}
			}
			else {
				for (int i = 0; i < right; i++) {
					D.push_front(D.back());
					D.pop_back();
					cnt++;
				}
			}
		}
	}
}

void Solve() {
	Input();
	Solution();

	cout << cnt << endl;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}