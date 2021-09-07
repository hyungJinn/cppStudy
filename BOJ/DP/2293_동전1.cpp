#include<cstdio>

using namespace std;

int main()
{
	int i, j, n, k, a[101], d[100001] = { 0, };

	scanf("%d %d", &n, &k);

	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	d[0] = 1;
	for (i = 1; i <= n; i++)
		for (j = a[i]; j <= k; j++)
			d[j] += d[j - a[i]];

	printf("%d", d[k]);

	return 0;
}