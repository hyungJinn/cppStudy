#include<cstdio>

int MAX(int a, int b) { return a > b ? a : b; }

int dp[10001], arr[10001];

int main()
{
	int i, n, ans = 0;
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	dp[1] = arr[0] + arr[1];
	dp[2] = arr[1] + arr[2];
	for (i = 3; i <= n; i++)
	{
		dp[i] = MAX(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
		dp[i] = MAX(dp[i], dp[i - 1]);
	}

	for(i = 1; i <= n; i++)
		ans = MAX(ans, dp[i]);


	printf("%d", ans);
	return 0;
}