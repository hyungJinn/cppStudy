// referred to https://jaimemin.tistory.com/742

#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 100000;

pair <int, int> employee[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); // to improve runtime
	int test_case;
	int n;

	cin >> test_case;

	for (int i = 0; i < test_case; i++)
	{
		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> employee[i].first >> employee[i].second;

		sort(employee, employee + n);

		int interviewR = employee[0].second;
		int cnt = 1;

		for (int i = 1; i < n; i++)
		{
			if (interviewR > employee[i].second)
			{
				cnt++;
				interviewR = employee[i].second;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}