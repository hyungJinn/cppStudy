// I referred to this site, https://dongyeollee.github.io/2018/08/06/Al/10826/.
// I understood this algorithm.

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

string dp[10001];
int n;

string calc(string s1, string s2)
{
	int i;
	string ret;
	int len1, len2;
	int a, b, c_before, c_now; //carry before, carry now

	len1 = s1.length();
	len2 = s2.length();

	c_now = 0;

	if (len1 < len2) {
		for (i = 0; i < len2 - len1; i++)
			s1.insert(s1.begin(), '0');
	}
	else if (len2 < len1) {
		for (i = 0; i < len1 - len2; i++)
			s2.insert(s2.begin(), '0');
	}

	for (i = len1 - 1; i >= 0; i--) {
		a = s1[i] - '0';
		b = s2[i] - '0';

		c_before = c_now;

		if (a + b + c_before < 10) {
			c_now = 0;
			ret += (a + b + c_before) + '0';
		}
		else {
			c_now = 1;
			ret += (a + b + c_before - 10) + '0';

			if (i == 0 && c_now == 1) ret += '1';
		}
	}
	reverse(ret.begin(), ret.end());

	return ret;
}

int main() {
	int i;
	cin >> n;
	dp[0] = '0';
	dp[1] = '1';
	for (i = 2; i <= n; i++) {
		dp[i] = calc(dp[i - 1], dp[i - 2]);
	}
	cout << dp[n];
	return 0;
}