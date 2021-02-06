// I referred to this site, https://yabmoons.tistory.com/519.

#include<cstdio>

#define MAX 16

int Max(int a, int b) { return a > b ? a : b; }

int Cost[MAX];
int Day[MAX];
int Dp[MAX];
int N;

void Input()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d %d", &Day[i], &Cost[i]);
}

void Solution()
{
	for (int i = N; i >= 1; i--)
	{
		if (i + Day[i] > N + 1) Dp[i] = Dp[i + 1];
		else Dp[i] = Max(Cost[i] + Dp[i + Day[i]], Dp[i + 1]);
	}
	printf("%d", Dp[1]);
}

void Solve()
{
	Input();
	Solution();
}

int main()
{
	Solve();

	return 0;
}