// I referred to this site: https://m.blog.naver.com/occidere/220794872664
// I understood this algorithm.

#include<cstdio>

using namespace std;

int min(int a, int b)
{
	return a > b ? b : a;
}

int main()
{
	int i, j, n, k, a[101], d[100001];
	scanf("%d %d", &n, &k);

	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for (i = 1; i <= k; i++)
		d[i] = 100001;
	d[0] = 0;

	for (i = 1; i <= n; i++)
		for (j = a[i]; j <= k; j++)
			d[j] = min(d[j], d[j - a[i]] + 1);

	if (d[k] == 100001) d[k] = -1;
	printf("%d", d[k]);

	return 0;
}