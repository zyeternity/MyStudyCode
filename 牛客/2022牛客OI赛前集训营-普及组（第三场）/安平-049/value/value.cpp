#include <bits/stdc++.h>
using namespace std;

inline void readd(int &k) {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x  = x * 10 + (ch - '0');
        ch = getchar();
    }
    k = x * w;
    return;
}

long long n;
long long a[5 * 100000 + 10];
long long ans;
struct temp {
    long long i, i_1;
};
queue<temp> bfs_use;
int main() {
    std::ios::sync_with_stdio(false);
    freopen("value.in", "r", stdin);
    freopen("value.out", "w", stdout);
    cin >> n;
    ans = n;
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = abs(a[i]);
        if (i != 0) {
            if (a[i] == a[i - 1]) {
                bfs_use.push({i - 1, i});
            }
        }
    }
    while (!bfs_use.empty()) {
        ans++;
        temp tp = bfs_use.front();
        bfs_use.pop();
        while (true) {
            if (tp.i - 1 >= 0 && tp.i_1 + 1 < n) {
                if (a[tp.i - 1] == a[tp.i_1 + 1]) {
                    ans++;
                    tp.i   = tp.i - 1;
                    tp.i_1 = tp.i + 1;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
