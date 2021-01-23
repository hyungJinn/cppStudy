// I referred to this site https://jaimemin.tistory.com/760
// I understood this algorithm.

#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

const int MAX = 300000;

int N, K;
int bag[MAX];
pair<int, int> jewerly[MAX];
priority_queue<int> pq;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K; // the number of jewelry and bag
	
	for (int i = 0; i < N; i++)
		cin >> jewerly[i].first >> jewerly[i].second; //weight, value
	
	for (int i = 0; i < K; i++)
		cin >> bag[i];

	sort(jewerly, jewerly + N);
	sort(bag, bag + K);

	long long sum = 0;
	int j = 0;
	for (int i = 0; i < K; i++)
	{
		while (j < N && jewerly[j].first <= bag[i])
			pq.push(jewerly[j++].second);

		if (!pq.empty())
		{
			sum += pq.top();
			pq.pop();
		}
	}
	cout << sum;
	return 0;
}