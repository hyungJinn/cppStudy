#include <stdio.h>
#include <stack>

using namespace std;

int main()
{
	char str[51];
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%s", &str);

		stack<char> st;
		int idx = 0;
		while (str[idx] != '\0')
		{
			if (str[idx] == '(') {
				st.push(str[idx]);
			}
			else if (str[idx] == ')') {
				if (!st.empty() && st.top() == '(') {
					st.pop();
				}
				else if (!st.empty() && st.top() == ')') {
					st.push(str[idx]);
				}
				else if (st.empty()) {
					st.push(str[idx]);
				}
			}
			++idx;
		}
		if (st.empty()) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}