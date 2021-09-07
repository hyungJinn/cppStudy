// I refer to this site, https://lmcoa15.tistory.com/25.

#include<cstdio>
#include<cstring>

#define MAX 100

int N;
int Arr[MAX][MAX];
bool Visitied[MAX];

void Initialize()
{
	memset(Visitied, false, sizeof(Visitied));
}

void Input()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &Arr[i][j]);
		}
	}
}

void DFS(int s)
{
	for (int f = 0; f < N; f++)
	{
		if (Arr[s][f] == 1 && Visitied[f] == false)
		{
			Visitied[f] = true;
			DFS(f);
		}
	}
}

void Solution()
{
	for (int i = 0; i < N; i++)
	{
		Initialize();
		DFS(i);

		for (int j = 0; j < N; j++)
		{
			if (Visitied[j] == true)
			{
				Arr[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", Arr[i][j]);
		}
		printf("\n");
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