// I refer to this site, https://yabmoons.tistory.com/30.
// I don't understand this algorithm.

#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

const int MAX = 8;

int N, M, space, answer;
int MAP[MAX][MAX];
int C_MAP[MAX][MAX];
bool Check[MAX * MAX];
bool Visit[MAX][MAX];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

vector<pair<int, int>> Empty, Virus;

int Bigger(int a, int b) { if (a > b) return a; return b; }

void Input()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &MAP[i][j]);
			if (MAP[i][j] == 0) Empty.push_back(make_pair(i, j));
			else if (MAP[i][j] == 2) Virus.push_back(make_pair(i, j));
		}
	}
	space = Empty.size();
}

void Copy_MAP()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			C_MAP[i][j] = MAP[i][j];
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

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (0 <= ny && 0 <= nx && ny < N && nx < M)
			{
				if (Visit[ny][nx] == false && C_MAP[ny][nx] == 0)
				{
					C_MAP[ny][nx] = 2;
					Visit[ny][nx] = true;
					Q.push(make_pair(ny, nx));
				}
			}
		}
	}
}

int Count_Safe_Area()
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (C_MAP[i][j] == 0) cnt++;
		}
	}
	return cnt;
}

void Spread_Virus()
{
	int cnt = 0;
	Copy_MAP();
	memset(Visit, false, sizeof(Visit));

	for (int i = 0; i < space; i++)
	{
		if (cnt == 3) break;
		if (Check[i] == true)
		{
			int y = Empty[i].first;
			int x = Empty[i].second;
			C_MAP[y][x] = 1;
			cnt++;
		}
	}
	for (int i = 0; i < Virus.size(); i++)
	{
		int y = Virus[i].first;
		int x = Virus[i].second;
		BFS(y, x);
	}

	int Temp_Answer = Count_Safe_Area();
	answer = Bigger(answer, Temp_Answer);
}

void Make_Wall(int idx, int cnt)
{
	if (cnt == 3)
	{
		Spread_Virus();
		return;
	}

	for (int i = idx; i < space; i++)
	{
		if (Check[i] == true) continue;
		Check[i] = true;
		Make_Wall(i, cnt + 1);
		Check[i] = false;
	}
}

void Solution()
{
	Make_Wall(0, 0);
}

void Solve()
{
	Input();
	Solution();
	printf("%d\n", answer);
}

int main()
{
	Solve();
	return 0;
}