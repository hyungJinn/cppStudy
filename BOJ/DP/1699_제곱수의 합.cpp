#include<cstdio>
#include<cmath>

using namespace std;

int min(int a, int b)
{
	return a > b ? b : a;
}

int main()
{
	int i, j, n, d[100001];

	scanf("%d", &n);

	for (i = 1; i <= n; i++) 
		d[i] = 100001;

	d[0] = 0;
	for (i = 1; i <= sqrt(n); i++)
		for (j = i * i; j <= n; j++)
			d[j] = min(d[j], d[j - i * i] + 1);

	printf("%d", d[n]);

	return 0;
}