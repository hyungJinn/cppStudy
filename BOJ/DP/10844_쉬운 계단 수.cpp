// I referred to this site, https://yabmoons.tistory.com/515.

#include<iostream>

#define endl "\n"
#define MAX 105
#define MODULER 1000000000

using namespace std;

int N;
long long dp[MAX][10];

void Input()
{
	cin >> N;
}

void Solution()
{
	int i, j;
	for (i = 1; i <= 9; i++) dp[1][i] = 1;
	for (i = 2; i <= N; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			if (j == 0) dp[i][j] = dp[i - 1][1];
			else if (j == 9) dp[i][j] = dp[i - 1][8];
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];

			dp[i][j] = dp[i][j] % MODULER;
		}
	}

	long long answer = 0;
	for (i = 0; i <= 9; i++) answer += dp[N][i];
	answer = answer % MODULER;
	cout << answer << endl;
}

void Solve()
{
	Input();
	Solution();
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	Solve();

	return 0;
}