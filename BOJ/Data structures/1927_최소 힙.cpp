#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

void input() {
    cin >> N;
}

void solution() {
    int X;
    for (int i = 0; i < N; i++) {
        cin >> X;
        if (X == 0) {
            if (pq.size() == 0) {
                cout << 0 << endl;
            }
            else {
                cout << pq.top() << endl;
                pq.pop();
            }
        }
        else {
            pq.push(X);
        }
    }
}

void solve() {
    input();
    solution();
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    solve();

    return 0;
}