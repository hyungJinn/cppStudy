#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define endl '\n'

using namespace std;

int M, P; //P : print number
int Count;
vector<int> comp;
queue<pair<int, int>> answer;

void initialization() {
	M = P = Count = 0;
	comp.clear();
	while (!answer.empty()) answer.pop();
}

void input() {
	int temp = 0;
	cin >> M >> P;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		answer.push(make_pair(i, temp));
		comp.push_back(temp);
	}
}

void solution() {
	pair<int, int> swap = make_pair(0,1);
	sort(comp.begin(), comp.end(), greater<int>());

	for (int j = 0; j < M;) {
		if (comp[j] == answer.front().second) {
			++Count;
			if (answer.front().first == P) break;
			answer.pop();
			++j;
		}
		else {
			swap = make_pair(answer.front().first, answer.front().second);
			answer.pop();
			answer.push(swap);
		}
	}
}

void solve() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		initialization();
		input();
		solution();
		cout << Count << endl;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	solve();

	return 0;
}