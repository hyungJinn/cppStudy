#include<cstdio>
#include<climits>
#include<queue>

#define MAX 100000 + 1

int Min(int a, int b) { return a < b ? a : b; }

int N, K;
bool Visit[MAX];
int Arr[MAX];
int Time = INT_MAX;

int dx[] = { 1, -1 };


void Input()
{
	scanf("%d %d", &N, &K);
}

void BFS(int a)
{
	std::queue<std::pair<int, int>> Q;
	Q.push(std::make_pair(a, 0));

	while (!Q.empty())
	{
		int x = Q.front().first;
		int t = Q.front().second;
		Q.pop();

		Visit[x] = true;

		if (x == K)
		{
			Arr[t]++;
			Time = Min(Time, t);
		}

		for (int i = 0; i < 2; i++)
		{
			int nx = x + dx[i];
			if (0 <= nx && nx < MAX)
			{
				if (Visit[nx] == false)
				{
					Q.push(std::make_pair(nx, t + 1));
				}
			}
		}

		if (x * 2 < MAX)
		{
			if (Visit[x * 2] == false)
			{
				Q.push(std::make_pair(x * 2, t + 1));
			}
		}
	}
	printf("%d\n%d", Time, Arr[Time]);
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