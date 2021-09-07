#include<iostream>

using namespace std;

int main()
{
	int coin[6] = { 500, 100, 50, 10, 5, 1 };
	int money, charge, remain, count = 0;
	cin >> money;

	charge = 1000 - money;

	for (int i = 0; i < 6; i++)
	{
		count += (charge / coin[i]);
		remain = (charge % coin[i]);
		charge = remain;
		if (charge == 0) break;
	}

	cout << count;
	return 0;
}