#include<iostream>
#include<string>

#define endl '\n'

using namespace std;

string oxQuiz;

void input()
{
	cin >> oxQuiz;
}

void solution()
{
	int sum = 0;
	int count = 0;
	int length = oxQuiz.length();
	for (int i = 0; i < length; i++)
	{
		if (oxQuiz[i] == 'O') count++;
		if (oxQuiz[i] == 'X') count = 0;
		sum += count;
	}
	cout << sum << endl;
}

void solve()
{
	int T;
	cin >> T;
	while (T--)
	{
		input();
		solution();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();

	return 0;
}