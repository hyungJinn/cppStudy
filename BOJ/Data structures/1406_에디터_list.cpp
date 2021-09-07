// I referred to this site, https://kih0902.tistory.com/28.
// I referred to this site, https://intaehwang.tistory.com/32.

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
				//--cursor가 가리키는 원소를 삭제
				//erase()는 삭제한 원소의 다음 원소를 가리키는 iterator를 반환
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

	for (auto lt = editor.begin(); lt != editor.end(); lt++) {
		cout << *lt;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}
