#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>

#define MAX 50

using namespace std;

int w, h;
int MAP[MAX][MAX];
int Visit[MAX][MAX];

int dx[] = { 0,0,1,-1,-1,1, -1, 1 };
int dy[] = { 1,-1,0,0,-1,-1, 1, 1 };

vector<pair<int, int>> V;

void Initialize()
{
	memset(MAP, 0, sizeof(MAP));
	memset(Visit, false, sizeof(Visit));
	V.clear();
}

void Input()
{
	scanf("%d %d", &w, &h);
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			scanf("%d", &MAP[i][j]);
			if (MAP[i][j] == 1) V.push_back(make_pair(i, j));
		}
	}
}

void BFS(int a, int b)
{
	queue<pair<int, int>> Q;
	Q.push(make_pair(a, b));
	Visit[a][b] = true;

	while (Q.empty() == 0)
	{
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();

		for (int i = 0; i < 8; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (0 <= ny && 0 <= nx && ny < h && nx < w)
			{
				if (MAP[ny][nx] == 1 && Visit[ny][nx] == false)
				{
					Q.push(make_pair(ny, nx));
					Visit[ny][nx] = true;
				}
			}
		}

	}
}

void Solution()
{
	int cnt = 0;
	for (int i = 0; i < V.size(); i++)
	{
		int y = V[i].first;
		int x = V[i].second;
		if (Visit[y][x] == false)
		{
			BFS(y, x);
			cnt++;
		}
	}
	printf("%d\n", cnt);
}

void Solve()
{
	while (1)
	{
		Initialize();
		Input();
		if (w == 0 && h == 0) break;
		Solution();
	}
}

int main()
{
	Solve();

	return 0;
}
