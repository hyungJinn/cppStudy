#include<iostream>
using namespace std;

int main()
{
	int thkg, fikg;
	int nkg, result = 0;
	int a, b, c, d;
	cin >> nkg;

	a = nkg / fikg;
	b = nkg % fikg;
	c = b / thkg;
	d = b % thkg;

	if (d == 0)
		cout << a + c << endl;
	else
		cout << -1 << endl;

	return 0;
}