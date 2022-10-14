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


int t;
int n, k;
int mins = 1e9, maxs = 0;
int a[1000000+10];

int main() {
    std::ios::sync_with_stdio(false);
    // freopen("array.in", "r", stdin);
    // freopen("array.out", "w", stdout);

    readd(t);
    while (t--) {
        readd(n);
        readd(k);
        for (int i = 0, temp; i < n; i++) {
            readd(a[i]);
            maxs = max(maxs, temp);
            mins = min(mins, temp);
        }

        if (maxs - mins <= 2 * k + n - 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
