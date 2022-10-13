#include <bits/stdc++.h>
using namespace std;

long long k, m, n;
bool cankill = false;

int main() {
    cin >> k >> m >> n;
    for (long long i = 0; i < m; i++) {
        long long a, b;
        cin >> a;
        cin >> b;
        if (a == 0) {
            cout << i + 1 << ' ';
        } else {
            long long cando = k / a;
            if (cando * b >= n) {
                cankill = true;
                cout << i + 1 << ' ';
            }
        }
    }
    if (!cankill) {
        cout << -1;
    }

    return 0;
}