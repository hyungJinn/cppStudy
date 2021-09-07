// I referred to this site, https://yabmoons.tistory.com/510

#include<cstdio>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int main()
{
	int i, n, arr[301], dp[301];
	scanf("%d", &n);

	arr[0] = 0;
	for (i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	dp[0] = arr[0];
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (i = 3; i <= n; i++)
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);

	printf("%d", dp[n]);
	return 0;
}