//I referred to this site, https://yabmoons.tistory.com/478.

#include <iostream>
#include <queue>

#define endl "\n"

using namespace std;

int N;
priority_queue<int> maxPQ, minPQ;

void Solution() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		if (maxPQ.size() > minPQ.size()) minPQ.push(-x);
		else maxPQ.push(x);

		if (!maxPQ.empty() && !minPQ.empty()) {
			if (maxPQ.top() > -minPQ.top()) {
				int maxValue = maxPQ.top();
				int minValue = -minPQ.top();

				maxPQ.pop(); minPQ.pop();

				maxPQ.push(minValue);
				minPQ.push(-maxValue);
			}
		}
		cout << maxPQ.top() << endl;
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