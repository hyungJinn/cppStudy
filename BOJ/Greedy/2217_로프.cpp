#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int k[100001];
	int w = 0;

	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> k[i];

	sort(k, k + n);

	for (int i = 0; i < n; i++)
		if (w < (n - i) * k[i])
			w = (n - i) * k[i];

	cout << w;

	return 0;
}