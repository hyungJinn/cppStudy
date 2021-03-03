// I refer to this site, https://yabmoons.tistory.com/29.

#include<iostream>
#include<vector>
#include<queue>
#define MAX 100
#define endl '\n'
using namespace std;

typedef struct {
	int y, x, z;
}Dir, Node;

Dir moveDir[6] = { {1,0, 0}, {-1,0,0}, {0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1} };

int M, N, H, day;
int graph[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
bool tomatoState;

queue<Node> Q;

void input()
{
	tomatoState = true;
	cin >> M >> N >> H;
	for (int z = 0; z < H; z++)
		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++)
			{
				cin >> graph[y][x][z];
				if (graph[y][x][z] == 0) tomatoState = false;
				if (graph[y][x][z] == 1) Q.push({ y,x,z });
			}
}

bool checkTomatoState()
{
	for (int z = 0; z < H; z++)
		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++)
				if (graph[y][x][z] == 0)
					return false;
	return true;
}

void bfs()
{
	while (!Q.empty())
	{
		int Qs = Q.size();
		for (int size = 0; size < Qs; size++)
		{
			int nowY = Q.front().y;
			int nowX = Q.front().x;
			int nowZ = Q.front().z;
			Q.pop();

			for (int i = 0; i < 6; i++)
			{
				int ny = nowY + moveDir[i].y;
				int nx = nowX + moveDir[i].x;
				int nz = nowZ + moveDir[i].z;

				if (0 <= ny && ny < N && 0 <= nx && nx < M && 0 <= nz && nz < H)
					if (graph[ny][nx][nz] == 0)
					{
						graph[ny][nx][nz] = 1;
						Q.push({ ny,nx,nz });
					}
			}
			if (Q.size() == 0 && checkTomatoState() == true)
			{
				cout << day << endl;
				return;
			}
			else if (Q.size() == 0 && checkTomatoState() == false)
			{
				cout << -1 << endl;
				return;
			}
		}
		day++;
	}
}

void solution()
{
	if (tomatoState == true)
	{
		cout << 0 << endl;
		return;
	}

	bfs();
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