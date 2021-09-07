#include<cstdio>
#include<queue>

#define MAX 100000 + 1

int N, K;
int Visit[MAX];

void Input()
{
	scanf("%d %d", &N, &K);
}

void BFS(int a)
{
	std::deque<int> dq;
	dq.push_back(a);
	Visit[a] = 1;

	while (!dq.empty())
	{
		int x = dq.front();
		dq.pop_front();

		if (x == K)
		{
			printf("%d", Visit[K] - 1);
			return;
		}
		if (x * 2 < MAX && Visit[x * 2] == 0)
		{
			dq.push_front(x * 2);
			Visit[x * 2] = Visit[x];
		}

		if (x + 1 < MAX && Visit[x + 1] == 0)
		{
			dq.push_back(x + 1);
			Visit[x + 1] = Visit[x] + 1;
		}

		if (0 <= x - 1 && Visit[x - 1] == 0)
		{
			dq.push_back(x - 1);
			Visit[x - 1] = Visit[x] + 1;
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