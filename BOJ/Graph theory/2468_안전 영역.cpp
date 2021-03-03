// I refer to this site, https://yabmoons.tistory.com/25.

#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define MAX 100
#define endl '\n'
using namespace std;

struct Node {
	int x, y;
};

int N;
int maxRainHeight, maxCount;
int arr[MAX][MAX];
int copyArr[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1, 0, 0 };

vector<Node> V;

int Max(int a, int b) { return a > b ? a : b; }

void initialize()
{
	maxCount = 0;
	memset(visited, false, sizeof(visited));
	V.clear();
}

void input()
{
	maxRainHeight = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			maxRainHeight = Max(maxRainHeight, arr[i][j]);
		}
	}
}

void copyArray()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			copyArr[i][j] = arr[i][j];
		}
	}
}

void makeArray(int h)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (h >= copyArr[i][j]) copyArr[i][j] = 0;
			else V.push_back({ i,j });
		}
	}

}

void bfs(int a, int b)
{
	queue<Node> Q;
	Q.push({ a, b });
	visited[a][b] = true;
	
	while (!Q.empty())
	{
		int nowX = Q.front().x;
		int nowY = Q.front().y;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = nowX + dx[i];
			int ny = nowY + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < N)
			{
				if (visited[nx][ny] == false && copyArr[nx][ny] != 0)
				{
					Q.push({ nx,ny });
					visited[nx][ny] = true;
				}
			}
		}
	}
}

void solution()
{
	int ans = 0;
	for (int h = 0; ; h++)
	{
		initialize();
		if (h > maxRainHeight) break;
		copyArray();
		makeArray(h);

		for (int i = 0; i < V.size(); i++)
		{
			int x = V[i].x;
			int y = V[i].y;

			if (visited[x][y] == false)
			{
				maxCount++;
				bfs(x, y);
			}
		}
		ans = Max(ans, maxCount);
	}
	cout << ans << endl;
}

void solve()
{
	input();
	solution();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}