#include <iostream>
#include <string>
#include <stack>

#define endl '\n'

using namespace std;

int result;
string str;
stack<int> s;

void input() {
	cin >> str;
}

void solution() {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') s.push(str[i]);
		else  {
			if (str[i-1] == '(') {
				s.pop();
				result += s.size();
			}
			else {
				result += 1;
				s.pop();
			}
		}
	}
}

void solve() {
	input();
	solution();

	cout << result << endl;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	solve();

	return 0;
}