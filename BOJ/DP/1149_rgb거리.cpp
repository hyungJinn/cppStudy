// I referred to this site, https://sihyungyou.github.io/baekjoon-1149/
// I understood this algorithm.

#include<cstdio>
#include<limits.h>

using namespace std;

int min(int a, int b) { return a > b ? b : a; }

int main()
{
	int i, j, n;
	int dp[1000][3], arr[1000][3];
	scanf("%d", &n);

	for (i = 0; i < n; i++)
		for (j = 0; j < 3; j++)
			scanf("%d", &arr[i][j]);

	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];

	for (i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
	}

	int max = INT_MAX;
	for (i = 0; i < 3; i++) {
		if (dp[n - 1][i] < max)
			max = dp[n - 1][i];
	}

	printf("%d", max);

	return 0;
}