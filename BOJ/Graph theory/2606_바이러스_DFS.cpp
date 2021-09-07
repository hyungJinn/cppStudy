#include<cstdio>

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

void DFS(int x)
{
	Visited[x] = true;

	for (int i = 1; i <= N; i++)
	{
		if (Matrix[x][i] == 1 && !Visited[i])
		{
			Cnt++; DFS(i);
		}
	}
}

void Solution()
{
	DFS(1);
	printf("%d", Cnt);
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