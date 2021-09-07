// I referred to this site, https://yangorithm.tistory.com/157.
// I understood this algorithm.

#include<iostream>

using namespace std;

char A[50][50], B[50][50];

void change(int x, int y)
{
	for (int i = x; i < x + 3; i++)
	{
		for (int j = y; j < y + 3; j++)
		{
			if (A[i][j] == '0') A[i][j] = '1';
			else A[i][j] = '0';
		}

	}
}

int main()
{
	int n, m;
	int result = 0;

	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> A[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> B[i][j];


	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j < m - 2; j++)
		{
			if (A[i][j] != B[i][j])
			{
				change(i, j);
				result++;
			}
		}
	}

	bool isDifferent = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (A[i][j] != B[i][j])
			{
				isDifferent = true;
			}

		}
	}

	if (isDifferent) cout << -1 << endl;
	else cout << result << endl;

	return 0;
}