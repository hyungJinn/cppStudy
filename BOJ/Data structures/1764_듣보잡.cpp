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

	//�Է�1
	//push_back�� ����ϸ� 2^n�������� �޸�(capacity)�� ��´�.
	//������, resize�� �̿��ϸ� �̸� �޸𸮸� �Ҵ��Ͽ� �ӵ��� ���� �� �ִ�.
	//v[i]�� �̿��Ͽ� �Է��� ���� �� �ִ�.
	V.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> V[i];
	}
	sort(V.begin(), V.end()); //�������� ����

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