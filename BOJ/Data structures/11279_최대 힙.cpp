#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

int N;
priority_queue<int> q;

void input() {
    cin >> N;
}

void solution() {
    int X;
    for (int i = 0; i < N; i++) {
        cin >> X;
        if (X == 0) {
            if (q.size() == 0) {
                cout << 0 << endl;
            }
            else {
                cout << q.top() << endl;
                q.pop();
            }
        }
        else {
            q.push(X);
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