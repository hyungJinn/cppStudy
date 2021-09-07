// I referred to this site: https://blog.naver.com/occidere/220793012348.
// I understood this algorithm.

#include<cstdio>

using namespace std;

int main()
{
	int i, j, T, n, m, a[21];

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &n);

		for (i = 1; i <= n; i++)
			scanf("%d", &a[i]);

		scanf("%d", &m);

		int d[10001] = { 0 };

		d[0] = 1;
		for (i = 1; i <= n; i++)
			for (j = a[i]; j <= m; j++)
				d[j] += d[j - a[i]];

		printf("%d \n", d[m]);
	}
	return 0;
}