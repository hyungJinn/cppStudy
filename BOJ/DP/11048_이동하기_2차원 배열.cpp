#include <cstdio>

#define MAX 1001

int Max(int a, int b) { return a > b ? a : b; }

int N, M;
int Arr[MAX][MAX], DP[MAX][MAX];

void Input()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%d", &Arr[i][j]);
}

void Solution()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (j == 1) DP[i][j] = DP[i - 1][j] + Arr[i][j];
			else DP[i][j] = Max(DP[i - 1][j], DP[i][j - 1]) + Arr[i][j];
		}
	}
	printf("%d", DP[N][M]);
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