// I refer to this site, https://jaimemin.tistory.com/636.

#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 100
#define endl '\n'

using namespace std;

typedef struct {
	int y, x;
}Dir;

Dir moveDir[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

int M, N, K;
int cnt;
int graph[MAX][MAX];
bool visited[MAX][MAX];

vector<int> V;

void input()
{
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int y = y1; y < y2; y++)
			for (int x = x1; x < x2; x++)
				graph[y][x] = 1;
	}
}

void dfs(int nowY, int nowX)
{
	visited[nowY][nowX] = true;
	cnt++;

	for (int i = 0; i < 4; i++)
	{
		int ny = nowY + moveDir[i].y;
		int nx = nowX + moveDir[i].x;

		if (0 <= ny && ny < M && 0 <= nx && nx < N)
			if (graph[ny][nx] == 0 && !visited[ny][nx])
				dfs(ny, nx);
	}

}

void solution()
{
	for (int y = 0; y < M; y++)
		for(int x = 0; x < N; x++)
			if (graph[y][x] == 0 && !visited[y][x])
			{
				cnt = 0;
				dfs(y, x);
				V.push_back(cnt);
			}
}

void solve()
{
	input();
	solution();

	cout << V.size() << endl;
	sort(V.begin(), V.end());
	for (int i = 0; i < V.size(); i++)
		cout << V[i] << " ";
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}