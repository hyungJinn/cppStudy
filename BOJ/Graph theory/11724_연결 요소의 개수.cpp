// I referred to this site, https://jaimemin.tistory.com/637.

#include <cstdio>
#include <vector>

const int MAX = 1000 + 1;

int N, M;
std::vector<int> graph[MAX];
bool visited[MAX];

void Input()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int node1, node2;
		scanf("%d %d", &node1, &node2);
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}
}

void DFS(int node)
{
	visited[node] = true;

	for (int i = 0; i < graph[node].size(); i++)
	{
		int next = graph[node][i];
		if (visited[next] == 0)
			DFS(next);
	}
}

void Solution()
{
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == 0)
		{
			DFS(i);
			cnt++;
		}
	}
	printf("%d\n", cnt);
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