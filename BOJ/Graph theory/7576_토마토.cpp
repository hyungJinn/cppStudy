// I referred to this site, https://yabmoons.tistory.com/10.

#include<cstdio>
#include<queue>

using namespace std;

#define MAX 1001

int N, M;
int MAP[MAX][MAX];
bool Visited[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

queue<pair<int, int>> Q;

void Input()
{
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &MAP[i][j]);
			if (MAP[i][j] == 1)
			{
				Q.push(make_pair(i, j));
				Visited[i][j] = true;
			}
		}
	}
}

bool Check_Tomato_State()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (MAP[i][j] == 0) return false;
		}
	}
	return true;
}

void BFS()
{
	int Day = 0;

	while (!Q.empty())
	{
		int Qsize = Q.size();
		for (int q = 0; q < Qsize; q++)
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
					if (MAP[nx][ny] == 0 && !Visited[nx][ny])
					{
						MAP[nx][ny] = 1;
						Visited[nx][ny] = true;
						Q.push(make_pair(nx, ny));
					}
				}
			}
		}
		Day++;
	}
	if (!Check_Tomato_State()) printf("-1\n");
	else printf("%d", Day - 1);
}

void Solution()
{
	BFS();
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