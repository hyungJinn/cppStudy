// I referred to this site, https://yabmoons.tistory.com/522.

#include <cstdio>

#define MAX 1001	

int Max(int a, int b) { return a > b ? a : b; }

int DP[MAX];
int Card[MAX];	
int N;

void Input()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &Card[i]);
}

void Solution()
{
	DP[1] = Card[1];
	for (int i = 2; i <= N; i++)
		for (int j = 1; j <= i; j++)
			DP[i] = Max(DP[i], Card[j] + DP[i - j]);
	printf("%d", DP[N]);
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