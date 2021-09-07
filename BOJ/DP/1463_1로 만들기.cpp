// I referred to this site https://sihyungyou.github.io/baekjoon-1463/
// I understood this algorithm.

#include <iostream>

using namespace std;

int min(int a, int b) {
    return a > b ? b : a;
}

int main() {

    int arr[1000001] = { 0, };
    int N;

    cin >> N;

    arr[1] = 0;
    for (int i = 2; i <= N; i++) {
        arr[i] = arr[i - 1] + 1;
        if (i % 2 == 0) arr[i] = min(arr[i], arr[i / 2] + 1);
        if (i % 3 == 0) arr[i] = min(arr[i], arr[i / 3] + 1);
    }

    cout << arr[N];

    return 0;
}