#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<queue>
#define endl '\n'
#define MAX 101
using namespace std;

struct Node {
	int x, y;
};

int N, M;
int map[MAX][MAX];
int check[MAX][MAX]; // -1: 미방문, 그 이상의 값들은 해당 좌표까지 벽을 부순 횟수

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void intput() {
	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = tmp[j] - '0';
			check[i][j] = -1;
		}
	}
}

void bfs() {
	deque<Node> Q;
	Q.push_back({ 0,0 });
	check[0][0] = 0;

	while (!Q.empty())
	{
		int nowX = Q.front().x;
		int nowY = Q.front().y;
		Q.pop_front();

		for (int i = 0; i < 4; i++)
		{
			int nx = nowX + dx[i];
			int ny = nowY + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
				if (check[nx][ny] == -1)
				{
					if (map[nx][ny] == 0) {
						check[nx][ny] = check[nowX][nowY];
						Q.push_front({ nx,ny }); // 동일한 level로 처리해 주어야 하는 경우는 앞에다 넣고
					}
					else {
						check[nx][ny] = check[nowX][nowY] + 1;
						Q.push_back({ nx,ny }); // 다음 level로 처리해 주어야 하는 경우는 뒤에다 넣는다
					}
				}
			}
		}
	}
}

void solve() {
	bfs();
	cout << check[N - 1][M - 1] << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	intput();
	solve();

	return 0;
}