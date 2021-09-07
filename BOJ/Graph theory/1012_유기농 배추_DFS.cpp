#include<cstdio>
#include<cstring>
#include<vector>

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

void DFS(int y, int x)
{
	Visit[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (0 <= nx && 0 <= ny && nx < M && ny < N)
		{
			if (Visit[ny][nx] == false && MAP[ny][nx] == 1)
			{
				Visit[ny][nx] = true;
				DFS(ny, nx);
			}
		}
	}
}

void Solution()
{
	for (int i = 0; i < V.size(); i++)
	{
		int y = V[i].first;
		int x = V[i].second;

		if (Visit[y][x] == false)
		{
			DFS(y, x);
			Ans++;
		}
			
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