// I referred to this site, https://yabmoons.tistory.com/143.

#include<cstdio>

#define MAX 1001

int N;
int Arr[MAX], DP[MAX], R_DP[MAX];

void Input()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &Arr[i]);
}

void Solution()
{
	for (int i = 0; i < N; i++)
	{
		DP[i] = 1;
		for (int j = 0; j < i; j++)
			if (Arr[j] < Arr[i] && DP[j] + 1 > DP[i]) DP[i] = DP[j] + 1;
	}

	for (int i = N - 1; i >= 0; i--)
	{
		R_DP[i] = 1;
		for (int j = N - 1; j > i; j--)
			if (Arr[i] > Arr[j] && R_DP[i] < R_DP[j] + 1) R_DP[i] = R_DP[j] + 1;

	}

	int Ans = 0;
	for (int i = 0; i < N; i++)
		if (Ans < DP[i] + R_DP[i] - 1) Ans = DP[i] + R_DP[i] - 1;

	printf("%d", Ans);
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
