// I referred to this site, https://yabmoons.tistory.com/7.

#include<cstdio>
#include<queue>

#define MAX 100000 + 1

int N, K;
bool Visited[MAX];

int dx[] = { 1, -1 };

void Input()
{
	scanf("%d %d", &N, &K);
}

void BFS(int a)
{
	std::queue<std::pair<int, int>> Q;
	Q.push(std::make_pair(a, 0));
	Visited[a] = true;

	while (!Q.empty())
	{
		int x = Q.front().first;
		int t = Q.front().second;
		Q.pop();

		if (x == K)
		{
			printf("%d", t);
			return;
		}

		for (int i = 0; i < 2; i++)
		{
			int nx = x + dx[i];
			if (0 <= nx && nx < MAX)
			{
				if (!Visited[nx])
				{
					Q.push(std::make_pair(nx, t + 1));
					Visited[nx] = true;
				}
			}
		}

		if (x * 2 < MAX)
		{
			if (!Visited[x * 2])
			{
				Q.push(std::make_pair(x * 2, t + 1));
				Visited[x * 2] = true;
			}
		}
	}
}

void Solution()
{
	BFS(N);
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