#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> answer;
vector<int> comp; //comparison
vector<int> v; //1 == "push" and 0 == "pop"

void input() {
	int temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		comp.push_back(temp);
	}
}

int solution() {
	int a = 0; //comp
	int b = 0;
	int count = 1;
	answer.push_back(0);
	for (int i = 0; i < n;) {
		a = comp[i];
		b = answer.back();
		if (a > b) {
			answer.push_back(count++);
			v.push_back(1);
		}
		else if (a < b) {
			return 0;
		}
		else {
			answer.pop_back();
			v.push_back(0);
			i = i + 1;
		}
	}
	return 1;
}

void solve() {
	input();
	if (solution()) {
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == 1) cout << "+" << '\n';
			else cout << "-" << '\n';
		}
	}
	else {
		cout << "NO";
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	solve();

	return 0;
}