// I refer to this site, https://yabmoons.tistory.com/73.

#include<iostream>
#include<string>
#include<queue>
#define MAX 1000
#define endl '\n'

using namespace std;

typedef struct {
	int y, x, block, count;
}Node;

int N, M;
int map[MAX][MAX];
bool visited[MAX][MAX][2]; // z = 1: noBreakBrick, 2:

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

void input()
{
	cin >> N >> M;
	for (int y = 0; y < N; y++)
	{
		string inp;
		cin >> inp;
		for (int x = 0; x < M; x++)
		{
			int tmp = inp[x] - '0';
			map[y][x] = tmp;
		}
	}
}

int bfs(int y, int x)
{
	queue<Node>Q;
	Q.push({ y,x,0,1 });
	visited[y][x][0] = true;

	while (!Q.empty())
	{
		int nowY = Q.front().y;
		int nowX = Q.front().x;
		int B = Q.front().block;
		int cnt = Q.front().count;
		Q.pop();

		if (nowY == N - 1 && nowX == M - 1)
			return cnt;

		for (int i = 0; i < 4; i++)
		{
			int ny = nowY + dy[i];
			int nx = nowX + dx[i];

			if (0 <= ny && ny < N && 0 <= nx && nx < M)
			{
				if (map[ny][nx] == 1 && B == 0)
				{
					visited[ny][nx][1] = true;
					Q.push({ ny,nx,B + 1,cnt + 1 });

				}
				else if (map[ny][nx] == 0 && !visited[ny][nx][B])
				{
					visited[ny][nx][B] = true;
					Q.push({ ny,nx,B,cnt + 1 });
				}
			}

		}
	}
	return -1;
}

void solution()
{
	int ans = bfs(0, 0);
	cout << ans << endl;
}

void solve()
{
	input();
	solution();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}