// I referred to this site, https://st-lab.tistory.com/78.

#include <cstdio>

#define MAX 15

int T;
int Arr[MAX][MAX];

void Input()
{
	scanf("%d", &T);
}

void Solution()
{
	int K, N;
	while (T--)
	{
		scanf("%d%d", &K, &N);

		for (int i = 0; i <= K; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (i == 0) Arr[0][j] = j;
				else if (j == 1) Arr[i][1] = 1;
				else Arr[i][j] = Arr[i][j] = Arr[i][j - 1] + Arr[i - 1][j];
			}
		}
		printf("%d\n", Arr[K][N]);
	}
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
