// I referred to this site, https://torbjorn.tistory.com/514

#include<cstdio>

int min(int a, int b) { return a > b ? b : a; }

const int INF = 987654321;
int i, j, t, n, arr[100001][3], dp[100001][3];

int main()
{
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;
		for (i = 0; i < n; i++)
			for (j = 0; j < 3; j++)
				scanf("%d", &arr[i][j]);

		dp[0][0] = INF;
		dp[0][1] = arr[0][1];
		dp[0][2] = dp[0][1] + arr[0][2];

		for (i = 1; i < n; i++)
		{
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][0];
			dp[i][1] = min(min(dp[i - 1][0], dp[i - 1][1]), min(dp[i - 1][2], dp[i][0])) + arr[i][1];
			dp[i][2] = min(min(dp[i - 1][1], dp[i - 1][2]), dp[i][1]) + arr[i][2];
		}
				
		printf("%d. %d\n",++t, dp[n - 1][1]);
	}
	return 0;
}