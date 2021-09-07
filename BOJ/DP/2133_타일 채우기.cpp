// I referred to this site, https://yabmoons.tistory.com/536.

#include <iostream>

#define endl '\n'
#define MAX 35
using namespace std;

int N;
int DP[MAX];

void Input()
{
	cin >> N;
}

void Solution()
{
	if (N % 2 == 1)
	{
		cout << 0 << endl;
		return;
	}
	DP[0] = 1;
	DP[1] = 0;
	DP[2] = 3;
	for (int i = 4; i <= N; i += 2)
	{
		DP[i] = DP[i - 2] * DP[2];
		for (int j = i - 4; j >= 0; j -= 2)
		{
			DP[i] = DP[i] + (DP[j] * 2);
		}
	}
	cout << DP[N] << endl;
}
void Solve()
{
	Input();
	Solution();
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solve();

	return 0;
}