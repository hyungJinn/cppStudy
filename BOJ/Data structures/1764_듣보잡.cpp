//I referred to this site, https://blockdmask.tistory.com/173.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define endl '\n'

using namespace std;

int N, M;

vector<string> V;
vector<string> result;

void Input() {
	cin >> N >> M;

	//입력1
	//push_back을 사용하면 2^n제곱으로 메모리(capacity)를 잡는다.
	//하지만, resize를 이용하면 미리 메모리를 할당하여 속도를 줄일 수 있다.
	//v[i]를 이용하여 입력을 받을 수 있다.
	V.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> V[i];
	}
	sort(V.begin(), V.end()); //오름차순 정렬

	string str;
	for (int i = 0; i < M; i++) {
		cin >> str;
		if (binary_search(V.begin(), V.end(), str)) {
			result.push_back(str);
		}
	}
	sort(result.begin(), result.end());
}

void Solution() {
	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
}

void Solve() {
	Input();
	Solution();
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	Solve();

	return 0;
}