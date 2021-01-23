#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 1001;
int N, L;
int arr[MAX];

int main()
{
	cin >> N >> L;
	int count = 1;
	int min;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	min = arr[0];
	for (int i = 0; i < N; i++)
	{
		if ((arr[i] - min) > L - 1)
		{
			count++;
			min = arr[i];
		}
	}

	cout << count << endl;

	return 0;
}