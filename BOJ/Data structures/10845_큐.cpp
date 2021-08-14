#include <iostream>
#include <queue>
#include <string>

#define endl '\n'

using namespace std;

int N;

void input() {
	cin >> N;
}

void solution() {
	queue<int> q;

	for (int i = 0; i < N; i++) {
		string text;
		cin >> text;
		if (text == "push") {
			int X;
			cin >> X;
			q.push(X);
		}
		else if (text == "pop") {
			if (!q.empty()) {
				cout << q.front() << endl;
				q.pop();
			}
			else
				cout << "-1\n";
		}
		else if (text == "size") {
			cout << q.size() << endl;
		}
		else if (text == "empty") {
			if (!q.empty()) {
				cout << "0\n";
			}
			else cout << "1\n";
		}
		else if (text == "front") {
			if (!q.empty()) {
				cout << q.front() << endl;
			}
			else cout << "-1\n";
		}
		else if (text == "back") {
			if (!q.empty()) {
				cout << q.back() << endl;
			}
			else cout << "-1\n";
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	solution();

	return 0;
}