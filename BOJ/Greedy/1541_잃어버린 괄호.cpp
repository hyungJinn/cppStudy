// writted by https://jaimemin.tistory.com/504

#include<iostream>
#include<string>
using namespace std;

int main()
{	
	string str;
	bool minus = false;
	int result = 0;
	string temp = "";

	cin >> str;

	for (int i = 0; i <= str.size(); i++)
	{
		if (str[i] == '-' || str[i] == '+' || str[i] == '\0')
		{
			if (minus)
				result -= stoi(temp);
			else
				result += stoi(temp);
			temp = "";
			if (str[i] == '-')
				minus = true;

			continue;
		}
		temp += str[i];
	}

	cout << result << endl;

	return 0;
}