// I referred to this site, https://yabmoons.tistory.com/525.

#include<cstdio>

#define MAX	1001
#define MODULER 10007

int DP[MAX][10];
int N;

void Input()
{
	scanf("%d", &N);
}

void Solution()
{
	for (int i = 0; i < 10; i++) DP[1][i] = 1;

	for(int i = 2; i <= N; i++)
		for(int j = 0; j < 10; j++)
			for (int k = j; k >= 0; k--)
			{
				DP[i][j] += DP[i - 1][k];
				DP[i][j] %= MODULER;
			}

	int sum = 0;
	for (int i = 0; i < 10; i++) sum += DP[N][i];
	sum %= MODULER;
	printf("%d", sum);
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