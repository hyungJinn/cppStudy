// I referred to this site, https://dailylifeofdeveloper.tistory.com/173.

#include <iostream>
#include <vector>

using namespace std;

int N, K;

vector<int> answer;
vector<int> visited;

void input() {
	cin >> N >> K;
	visited.resize(N + 1, 0);
}

void solution() {
	int num = K;
	answer.push_back(num);
	visited[num] = 1;

	while (answer.size() < N) {
		int cycle = 0;
		while (cycle < K) {
			num = (num == N) ? 1 : num + 1;
			if (visited[num] == 0) cycle += 1;
		}
		answer.push_back(num);
		visited[num] = 1;
	}
}

void solve() {
	cout << '<';
	for (int i = 0; i < N; i++) {
		if (i != N - 1)
			cout << answer[i] << ", ";
		else
			cout << answer[i];
	}
	cout << '>';
}

int main()
{
	input();
	solution();
	solve();

	return 0;
}