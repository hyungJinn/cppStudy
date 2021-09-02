// I referred to this site, https://kih0902.tistory.com/28.

#include <iostream>
#include <string>
#include <list>

#define endl '\n'

using namespace std;

int M;
string str;

list<char> editor;

void Input() {
	cin >> str;
	cin >> M;
}

void Solution() {
	editor.assign(str.begin(), str.end());
	auto cursor = editor.end();

	while (M--) {
		char tmp;
		cin >> tmp;

		if (tmp == 'L') {
			if (cursor != editor.begin()) {
				cursor--;
			}
		}
		else if (tmp == 'D') {
			if (cursor != editor.end()) {
				cursor++;
			}
		}
		else if (tmp == 'B') {
			if (cursor != editor.begin()) {
				cursor = editor.erase(--cursor);
			}
		}
		else if (tmp == 'P') {
			char c;
			cin >> c;
			editor.insert(cursor, c);
		}
	}
}

void Solve() {
	Input();
	Solution();

	for (auto it = editor.begin(); it != editor.end(); it++) {
		cout << *it;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}