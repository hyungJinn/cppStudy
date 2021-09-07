#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

int N;
priority_queue<int> pq;

void Solution() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        if (x == 0) {
            if (pq.size() == 0) {
                cout << 0 << endl;
            }
            else {
                cout << pq.top() << endl;
                pq.pop();
            }
        }
        else {
            pq.push(x);
        }
    }
}

void Solve() {
    Solution();
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Solve();

    return 0;
}
