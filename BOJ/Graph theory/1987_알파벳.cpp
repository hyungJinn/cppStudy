// I refer to this site, https://yabmoons.tistory.com/84.

#include<iostream>
#define MAX 20
#define endl '\n'
using namespace std;

int R, C, ans;
char map[MAX][MAX];
bool visited[26];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int Max(int a, int b) { return a > b ? a : b; }

void input()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
		}
	}
}

void dfs(int nowX, int nowY, int cnt)
{
	ans = Max(ans, cnt);

	for (int i = 0; i < 4; i++)
	{
		int nx = nowX + dx[i];
		int ny = nowY + dy[i];

		if (0 <= nx && nx < R && 0 <= ny && ny < C)
		{
			if (visited[map[nx][ny] - 'A'] == false)
			{
				visited[map[nx][ny] - 'A'] = true;
				dfs(nx, ny, cnt + 1);
				visited[map[nx][ny] - 'A'] = false;
			}
		}
	}
}

void solution()
{
	visited[map[0][0] - 'A'] = true;
	dfs(0, 0, 1);

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
