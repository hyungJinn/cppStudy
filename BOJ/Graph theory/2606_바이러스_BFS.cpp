#include<cstdio>
#include<queue>

#define MAX 101

int N, M, Cnt;
int Matrix[MAX][MAX];
bool Visited[MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void Input()
{
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int Start, End;
		scanf("%d %d", &Start, &End);
		Matrix[Start][End] = 1;
		Matrix[End][Start] = 1;
	}
}

void BFS(int V)
{
	std::queue<int> Q;
	Q.push(V);
	Visited[V] = true;

	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();

		for (int i = 1; i <= N; i++)
		{
			if (Matrix[x][i] == 1 && !Visited[i])
			{
				Q.push(i);
				Visited[i] = true;
				Cnt++;
			}
		}
	}
	printf("%d", Cnt);
}

void Solution()
{
	BFS(1);
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