// I referred to this site, https://yabmoons.tistory.com/87.

#include<cstdio>

#define MAX 1001

int N;
int DP[MAX], Arr[MAX];

void Input()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &Arr[i]);
}

void Solution()
{
	int Max = 0;
	for (int i = 0; i < N; i++)
	{
		DP[i] = Arr[i];
		for (int j = 0; j < i; j++)
			if (Arr[j] < Arr[i] && DP[j] + Arr[i] > DP[i]) DP[i] = DP[j] + Arr[i];
		if (Max < DP[i]) Max = DP[i];
	}
	printf("%d", Max);
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