#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int array[1000];
	int sum = 0;
	int a = 0;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> array[i];

	sort(array, array + n);

	for (int i = 0; i < n; i++)
	{
		a += array[i];
		sum += a;
	}

	cout << sum << endl;

	return 0;
}