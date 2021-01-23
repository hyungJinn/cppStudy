#include<iostream>

using namespace std;

int main()
{
	int i = 1;

	while (1)
	{
		int L, P, V;
		cin >> L >> P >> V;
		if (!L && !P && !V) { break; }
		int r = (V % P) > L ? L : (V % P);
		int result = (V / P) * L + r;
		cout << "Case " << i++ << ": " << result << endl;
	}

	return 0;
}