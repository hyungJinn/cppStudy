// I referred to this site, https://yabmoons.tistory.com/9.

#include<cstdio>
#include<algorithm>
#include<queue>
#include<string>
#include<vector>

#define MAX 25
using namespace std;

int N, Area_Num;
int MAP[MAX][MAX];
bool Visited[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

vector<pair<int, int>> V;
vector<int> Area_Cnt;

void Input()
{
	Area_Num = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", &MAP[i][j]);
			if (MAP[i][j] == 1) V.push_back(make_pair(i, j));
		}
	}
}

void BFS(int a, int b)
{
	queue<pair<int, int>> Q;
	Q.push(make_pair(a, b));
	Visited[a][b] = true;

	int Cnt = 1;
	while (!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && 0 <= ny && nx < N && ny < N)
			{
				if (MAP[nx][ny] == 1 && !Visited[nx][ny])
				{
					Visited[nx][ny] = true;
					Q.push(make_pair(nx, ny));
					Cnt++;
				}
			}
		}
	}
	Area_Num++;
	Area_Cnt.push_back(Cnt);
}

void Solution()
{
	for (int i = 0; i < V.size(); i++)
	{
		int x = V[i].first;
		int y = V[i].second;

		if (!Visited[x][y]) BFS(x, y);
	}
	sort(Area_Cnt.begin(), Area_Cnt.end());

	printf("%d\n", Area_Num);
	for (int i = 0; i < Area_Num; i++)
	{
		printf("%d\n", Area_Cnt[i]);
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
