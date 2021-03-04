// I refer to this site, https://yabmoons.tistory.com/55.

#include<iostream>
#include<queue>
#include<cstring>
#define endl '\n'
#define MAX 100
using namespace std;

typedef struct {
	int y, x;
}Node;

int N;
char map[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void input()
{
	cin >> N;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> map[y][x];
}

void colorBlindness()
{
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			if (map[y][x] == 'G') map[y][x] = 'R';
}

void bfs(int y, int x)
{
	queue<Node> Q;
	Q.push({ y,x });
	visited[y][x] = true;

	while (!Q.empty())
	{
		int nowY = Q.front().y;
		int nowX = Q.front().x;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = nowY + dy[i];
			int nx = nowX + dx[i];

			if (0 <= ny && ny < N && 0 <= nx && nx < N)
			{
				if (map[ny][nx] == map[nowY][nowX] && !visited[ny][nx])
				{
					visited[ny][nx] = true;
					Q.push({ ny,nx });
				}
			}
		}
	}
}

void solution()
{
	int ans = 0;
	int ans2 = 0;

	for(int y = 0; y < N; y++)
		for(int x = 0; x < N; x++)
			if (!visited[y][x])
			{
				bfs(y, x);
				ans++;
			}

	memset(visited, false, sizeof(visited));
	colorBlindness();

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			if (!visited[y][x])
			{
				bfs(y, x);
				ans2++;
			}

	cout << ans << " " << ans2 << endl;
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