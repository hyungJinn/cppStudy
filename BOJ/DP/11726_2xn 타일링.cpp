// I referred to this site: https://blog.naver.com/kks227/220777103650.
// I understood this algorithm.

#include<cstdio>

using namespace std;

int main()
{
	int n;
	int dp[1001] = { 0, };
	scanf("%d", &n);

	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;

	printf("%d", dp[n]);

	return 0;
}