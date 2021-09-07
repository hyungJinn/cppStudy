// I referred to this site, https://yabmoons.tistory.com/5.

#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

#define MAX 50

int N, M, K, Ans;
int MAP[MAX][MAX];
bool Visit[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

vector<pair<int, int>> V;

void Initialize()
{
	Ans = 0;
	memset(MAP, 0, sizeof(MAP));
	memset(Visit, false, sizeof(Visit));
	V.clear();
}

void Input()
{
	scanf("%d %d %d", &M, &N, &K);
	for (int i = 0; i < K; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		MAP[y][x] = 1;
		V.push_back(make_pair(y, x));
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

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (0 <= nx && 0 <= ny && nx < M && ny < N)
			{
				if (Visit[ny][nx] == false && MAP[ny][nx] == 1)
				{
					Q.push(make_pair(ny, nx));
					Visit[ny][nx] = true;
				}
			}
		}
	}
	Ans++;
}

void Solution()
{
	for (int i = 0; i < V.size(); i++)
	{
		int y = V[i].first;
		int x = V[i].second;

		if (Visit[y][x] == false)
			BFS(y, x);
	}
}

void Solve()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		Initialize();
		Input();
		Solution();

		printf("%d\n", Ans);
	}
}

int main()
{
	Solve();
	return 0;
}