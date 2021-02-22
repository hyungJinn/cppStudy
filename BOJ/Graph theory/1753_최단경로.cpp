// I refer to this site, https://yabmoons.tistory.com/376.
// I don't understand this algorithm.

#include<cstdio>
#include<queue>
#include<vector>

#define MAX 20010
#define INF 987654321
using namespace std;

int V, E, start;
int Dist[MAX];
vector<pair<int, int>> vertex[MAX];

void Input()
{
	scanf("%d %d %d", &V, &E, &start);
	for (int i = 0; i < E; i++)
	{
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		vertex[a].push_back(make_pair(b, c));
	}
	for (int i = 1; i <= V; i++) Dist[i] = INF;
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
	for (int i = 1; i <= V; i++)
	{
		if (Dist[i] == INF) printf("INF\n");
		else printf("%d\n", Dist[i]);
	}
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