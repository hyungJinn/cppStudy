#include<cstdio>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int main()
{
	int i, j, n, dp[501][501];
	int max_value = 0;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
		for (j = 0; j <= i; j++)
			scanf("%d", &dp[i][j]);

	for (i = 1; i < n; i++)
		for (j = 0; j <= i; j++) {
			if (j == 0) dp[i][j] += dp[i - 1][j];
			else if (j == i) dp[i][j] += dp[i - 1][j - 1];
			else dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
		}

	for (i = 0; i < n; i++)
		if (dp[n - 1][i] > max_value) max_value = dp[n - 1][i];

	printf("%d", max_value);
	return 0;
}