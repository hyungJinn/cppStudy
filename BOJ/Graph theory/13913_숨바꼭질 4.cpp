// I referred to this site, https://jaimemin.tistory.com/584.

#include<cstdio>
#include<queue>

#define MAX 100000 + 1

int N, K;
bool Visit[MAX];
int Parent[MAX];

std::vector<int> Path;

void Input()
{
	scanf("%d %d", &N, &K);
}

void BFS(int a)
{
	std::queue<std::pair<int, int>> Q;
	Q.push(std::make_pair(a, 0));
	Visit[a] = true;

	while (!Q.empty())
	{
		int x = Q.front().first;
		int t = Q.front().second;
		Q.pop();

		if (x == K)
		{
			int idx = x;
			while (idx != N)
			{
				Path.push_back(idx);
				idx = Parent[idx];
			}
			Path.push_back(N);

			printf("%d\n", t);
			for(int i = Path.size()-1; i >= 0; i--)
				printf("%d ", Path[i]);

			return;
		}

		if (x + 1 < MAX && Visit[x + 1] == 0)
		{
			Q.push(std::make_pair(x + 1, t + 1));
			Parent[x + 1] = x;
			Visit[x + 1] = true;
		}

		if (0 <= x - 1 && Visit[x - 1] == 0)
		{
			Q.push(std::make_pair(x - 1, t + 1));
			Parent[x - 1] = x;
			Visit[x - 1] = true;
		}

		if (x * 2 < MAX && Visit[x * 2] == 0)
		{
			Q.push(std::make_pair(x * 2, t + 1));
			Parent[x * 2] = x;
			Visit[x * 2] = true;
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