// I referred to this site, https://yabmoons.tistory.com/518.

#include<cstdio>

#define MAX 101

int N;
long long dp[MAX];

void Input()
{
	scanf("%d", &N);
}

void Solution()
{
	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = dp[5] = 2;
	for (int i = 6; i <= N; i++)
		dp[i] = dp[i - 1] + dp[i - 5];
	printf("%lld\n", dp[N]);

}
void Solve()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		Input();
		Solution();
	}
}

int main()
{
	Solve();

	return 0;
}