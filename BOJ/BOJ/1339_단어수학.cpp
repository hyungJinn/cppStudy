//referred to https ://yabmoons.tistory.com/132

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool cmp(int A, int B)
{
	if (A > B) return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int alphabet[26] = { 0, };
	vector<string> v;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string word; cin >> word;
		v.push_back(word);
	}

	for (int i = 0; i < N; i++)
	{
		string s = v[i];
		int len = s.length();
		int pow = 1;

		for (int j = len - 1; j >= 0; j--)
		{
			int tmp = s[j] - 'A';
			alphabet[tmp] = alphabet[tmp] + pow;
			pow = pow * 10;
		}
	}
	sort(alphabet, alphabet + 26, cmp);

	int answer = 0;
	int num = 9;
	for (int i = 0; i < 26; i++)
	{
		if (alphabet[i] == 0) break;
		answer = answer + (alphabet[i] * num);
		num--;
	}

	cout << answer << endl;

	return 0;
}