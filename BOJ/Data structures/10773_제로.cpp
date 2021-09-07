#include <iostream>
#include <vector>

using namespace std;

int K, answer;
vector<int> s;

void input() {
	int value;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> value;
		if (value == 0) {
			s.pop_back();
		}
		else {
			s.push_back(value);
		}
	}
}

void solution() {
	int size = s.size();
	for (int i = 0; i < size; i++) {
		answer += s[i];
	}
	cout << answer;
}

int main() {
	input();
	solution();

	return 0;
}