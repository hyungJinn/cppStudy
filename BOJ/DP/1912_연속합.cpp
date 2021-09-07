#include<cstdio>

int MAX(int a, int b) { return a > b ? a : b; }

int dp[100001], arr[100001];

int main()
{
	int i, n, ans;
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	for (i = 1; i <= n; i++)
	{
		if ((dp[i - 1] + arr[i]) >= arr[i])
			dp[i] = dp[i - 1] + arr[i];
		else
			dp[i] = arr[i];
	}

	ans = dp[1];
	for (i = 2; i <= n; i++)
		ans = MAX(ans, dp[i]);

	printf("%d", ans);

	return 0;
}