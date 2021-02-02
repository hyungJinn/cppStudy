// I referred to this site, https://sihyungyou.github.io/baekjoon-11053/.

#include <cstdio>

int MAX(int a, int b) { return a > b ? a : b; }

int dp[1001], arr[1001];

int main()
{
	int i, j, n, ans = 0;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (j = 0; j < i; j++)
			if ((arr[i] > arr[j]) && (dp[j] + 1 > dp[i])) dp[i] = dp[j] + 1;
	}

	for(i = 0; i < n; i++)
		ans = MAX(ans, dp[i]);

	printf("%d", ans);
	return 0;
}