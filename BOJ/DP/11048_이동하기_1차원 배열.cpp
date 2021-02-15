#include <cstdio>

#define MAX 1001

int Max(int a, int b) { return a > b ? a : b; }

int N, M;
int DP[MAX];

void Input()
{
	scanf("%d %d", &N, &M);
}

void Solution()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1, d; j <= M; j++)
		{
			scanf("%d", &d);
			DP[j] = Max(DP[j - 1], DP[j]) + d;
		}
	}
	printf("%d", DP[M]);
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