// I referred to this site https://yabmoons.tistory.com/414
// I understood this algorithm.

#include<iostream>
#include<queue>

#define MAX 100000
using namespace std;

int N;
int Arr[MAX];

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> Arr[i];
	}
}

void Solution()
{
	priority_queue<int, vector<int>, greater<int>> PQ;
	for (int i = 0; i < N; i++) PQ.push(Arr[i]);

	int Answer = 0;
	int Compare_Cnt = 0;

	while (PQ.empty() == 0)
	{
		if (Compare_Cnt == N - 1) break;
		int num1 = PQ.top(); PQ.pop();
		int num2 = PQ.top(); PQ.pop();

		Answer += (num1 + num2);
		PQ.push(num1 + num2);
		Compare_Cnt++;
	}
	cout << Answer << endl;
}

void Solve()
{
	Input();
	Solution();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solve();

	return 0;
}