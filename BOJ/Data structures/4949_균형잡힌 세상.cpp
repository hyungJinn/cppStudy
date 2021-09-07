#include <iostream>
#include <string>
#include <stack>

#define endl '\n'

using namespace std;

bool flag;
string str;

stack<int> S;

void Initialization() {
	while (!S.empty()) S.pop();
	flag = false;
}

void Input() {
	getline(cin, str);
}

void Solution() {
	//cout << str << endl;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			S.push(0); // ( = 0
		}
		else if (str[i] == '[') {
			S.push(1); // [ = 1
		}
		else if (str[i] == ')') {
			if (S.empty()) {
				flag = true;
				break;
			}
			else if (S.top() == 0) {
				S.pop();
			}
			else {
				flag = true;
				break;
			}
		}
		else if (str[i] == ']') {
			if (S.empty()) {
				flag = true;
				break;
			}
			else if (S.top() == 1) {
				S.pop();
			}
			else {
				flag = true;
				break;
			}
		}
	}
}

void Solve() {
	while (1) {
		Input();
		Solution();
		if (str.length() == 1 && str[0] == '.') break;
		if (!flag && S.empty()) cout << "yes" << endl;
		else cout << "no" << endl;
		Initialization();
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}