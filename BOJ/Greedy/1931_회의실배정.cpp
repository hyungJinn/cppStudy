// written by https://kim6394.tistory.com/67 

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Time
{
	int begin;
	int end;
};

bool cmp(Time f, Time s)
{
	if (f.end == s.end)
		return f.begin < s.begin;
	else
		return f.end < s.end;
}

int main()
{
	int n;
	cin >> n;

	vector<Time> t(n);
	for (int i = 0; i < n; i++)
	{
		cin >> t[i].begin >> t[i].end;
	}

	sort(t.begin(), t.end() , cmp);

	int cnt = 0;
	int end = 0;

	for (int i = 0; i <t.size(); i++)
	{
		if (end <= t[i].begin)
		{
			end = t[i].end;
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}