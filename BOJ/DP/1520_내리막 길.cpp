// I referred to this site, https://yabmoons.tistory.com/340.

#include<cstdio>

#define MAX 500

int N, M, Ans;
int MAP[MAX][MAX];
int DP[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void Input()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &MAP[i][j]);
			DP[i][j] = -1;
		}
	}
}

int DFS(int x, int y)
{
	if (x == N - 1 && y == M - 1) return 1;
	if (DP[x][y] != -1) return DP[x][y];

	DP[x][y] = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < N && ny < M)
		{
			if (MAP[nx][ny] < MAP[x][y])
			{
				DP[x][y] += DFS(nx, ny);
			}
		}
	}
	return DP[x][y];
}

void Solution()
{
	Ans = DFS(0, 0);
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
