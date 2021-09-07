// I referred to this site, https://yabmoons.tistory.com/6.

#include <cstdio>
#include <cstring>
#include <queue>

#define MAX 1001

int N, M, V;
int Matrix[MAX][MAX]; // Adjacency matrix
bool Visited[MAX];

void Input()
{
	scanf("%d %d %d", &N, &M, &V);
	for (int i = 0; i < M; i++)
	{
		int Start, End;
		scanf("%d %d", &Start, &End);
		Matrix[Start][End] = 1;
		Matrix[End][Start] = 1;
	}
}

void DFS(int x)
{
	Visited[x] = true;
	printf("%d ", x);
	for (int i = 1; i <= N; i++)
	{
		if (Matrix[x][i] == 1 && !Visited[i]) DFS(i);
	}
}

void BFS()
{
	std::queue<int> Q;
	Q.push(V);
	Visited[V] = true;

	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();

		printf("%d ", x);
		for (int i = 1; i <= N; i++)
		{
			if (Matrix[x][i] == 1 && !Visited[i])
			{
				Q.push(i);
				Visited[i] = true;
			}
		}
	}
}

void Solution()
{
	DFS(V);
	memset(Visited, false, sizeof(Visited));
	printf("\n");
	BFS();
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