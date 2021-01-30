// I referred to this site, https://jaemin8852.tistory.com/255.
// I understood this algorithm.

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int a[10001], b[10001], sum[10004], carry;

int main()
{
	int i;
	string str1, str2;
	cin >> str1 >> str2;

	for (i = 0; i < str1.length(); i++)
	{
		char temp = str1.at(i);
		a[str1.length() - i] = atoi(&temp);
	}
	for (i = 0; i < str2.length(); i++)
	{
		char temp = str2.at(i);
		b[str2.length() - i] = atoi(&temp);
	}
	for (i = 1; i <= max(str1.length(), str2.length()); i++) {
		sum[i] = a[i] + b[i] + carry;

		if (sum[i] >= 10) {
			sum[i] -= 10;
			carry = 1;
		}
		else carry = 0;
	}

	if (carry) cout << 1;
	for (i = 0; i < max(str1.length(), str2.length()); i++)
	{
		cout << sum[max(str1.length(), str2.length()) - i];
	}
	return 0;
}
