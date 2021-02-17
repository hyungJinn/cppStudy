// I referred to this site, https://cocoon1787.tistory.com/115.

#include<cstdio>
#include<queue>

#define MAX 101

int N, M;
char MAP[MAX][MAX];
bool Visited[MAX][MAX];
int Ans[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void Input()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", MAP[i]);
	}
}

void BFS(int x, int y)
{
	std::queue<std::pair<int, int>> Q;
	Q.push(std::make_pair(x, y));

	Visited[x][y] = true;

	while (!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;

		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && 0 <= ny && nx < N && ny < M)
			{
				if (MAP[nx][ny] == '1' && !Visited[nx][ny])
				{
					Q.push(std::make_pair(nx, ny));
					Visited[nx][ny] = true;
					Ans[nx][ny] = Ans[x][y] + 1;
				}
			}
		}
	}
	printf("%d\n", Ans[N - 1][M - 1] + 1);
}

void Solution()
{
	BFS(0, 0);
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