#include<iostream>
#define endl '\n'

int N;

using namespace std;

void input()
{
	cin >> N;
}

void solution()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << "*";
		}
		cout << '\n';
	}
}

void solve()
{
	input();
	solution();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	
	return 0;
}