#include <iostream>

using namespace std;

int main()
{
	int coin[10] = { 0 };
	int n, k;
	int count = 0;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> coin[i];

	for (int j = n - 1; j >= 0; j--)
	{
		int r; //remain
		count += k / coin[j];
		r = k % coin[j];
		k = r;
	}

	cout << count << endl;

	return 0;
}