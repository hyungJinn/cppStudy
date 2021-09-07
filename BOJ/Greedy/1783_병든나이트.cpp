// I referred to this site  https://lipcoder.tistory.com/entry/병든-나이트-백준-1783번
// I understood this algorithm.

#include<iostream>

using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int N, M;
	cin >> N >> M;

	if (N == 1)
		cout << 1 << endl;
	else if (N == 2)
		cout << min(4, (M + 1) / 2) << endl;
	else if (M < 7)
		cout << min(4, M) << endl;
	else
		cout << M - 7 + 5 << endl;

	return 0;
}