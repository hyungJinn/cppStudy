#include<cstdio>
#include<queue>
#include<vector>

#define MAX 1001
#define INF (1000 - 1) * 100000 + 1
using namespace std;

int N, M, start, finish;
int Dist[MAX];
vector<pair<int, int>> vertex[MAX];

void Input()
{
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		vertex[a].push_back(make_pair(b, c));
	}
	scanf("%d %d", &start, &finish);
	for (int i = 1; i <= N; i++) Dist[i] = INF;
}

void Solution()
{
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	Dist[start] = 0;

	while (pq.empty() == 0)
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < vertex[cur].size(); i++)
		{
			int next = vertex[cur][i].first;
			int nCost = vertex[cur][i].second;

			if (Dist[next] > cost + nCost)
			{
				Dist[next] = cost + nCost;
				pq.push(make_pair(-Dist[next], next));
			}
		}
	}
	printf("%d\n", Dist[finish]);
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