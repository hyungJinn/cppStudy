#include <iostream>

#define endl '\n'

using namespace std;

int n, sum;

void Solution() {
	cin >> n;
	for (int i = 1; i <= n; i++) sum += i;
	cout << sum << endl;
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