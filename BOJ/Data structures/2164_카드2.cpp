#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

int N;
queue<int> q;

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) q.push(i);
}

void solution() {
	int Count = 1;

	while (q.size() > 1) {
		if ((Count % 2) == 1) {
			q.pop();
		}
		else {
			int temp;
			temp = q.front();
			q.push(temp);
			q.pop();
		}
		++Count;
	}
}

void solve() {
	input();
	solution();

	cout << q.front() << endl;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	solve();

	return 0;
}