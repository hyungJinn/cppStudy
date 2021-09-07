#include<iostream>
#include<queue>
#include<cstring>
#define MAX 300
#define endl '\n'

using namespace std;

typedef struct {
	int y, x;
}Node;

int I;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[8] = { 1,2,1,2,-1,-2,-1,-2 };
int dy[8] = { 2,1,-2,-1,-2,-1,2,1 };

Node start, finish;

void initialize()
{
	memset(map, 0, sizeof(map));
	memset(visited, false, sizeof(visited));
}

void input()
{
	cin >> I;
	cin >> start.x >> start.y;
	cin >> finish.x >> finish.y;
}

void bfs()
{
	queue<Node> Q;
	Q.push({ start.y, start.x });
	visited[start.y][start.x] = true;

	while (!Q.empty())
	{
		int nowY = Q.front().y;
		int nowX = Q.front().x;
		Q.pop();

		if (nowY == finish.y && nowX == finish.x)
			return;

		for (int i = 0; i < 8; i++)
		{
			int ny = nowY + dy[i];
			int nx = nowX + dx[i];

			if(0 <= ny && ny < I && 0 <= nx && nx < I)
				if (!visited[ny][nx])
				{
					Q.push({ ny,nx });
					visited[ny][nx] = true;
					map[ny][nx] = map[nowY][nowX] + 1;
				}
		}
	}
}

void solve()
{
	int T;
	cin >> T;
	while (T--)
	{
		initialize();
		input();
		bfs();
		cout << map[finish.y][finish.x] << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}