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

inline void readlld(long long &k) {
    long long x = 0, w = 1;
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

long long n, m;
long long a[500000 + 10], b[500000 + 10];
long long sss[500000 * 2 + 10];
long long ks = 0;

// #define len_s(x, i) (abs(x - a[i]) + abs(a[i] - b[i]) + abs(b[i] - x))

long long ans = 0;

int main() {
    std::ios::sync_with_stdio(false);
    freopen("dock.in", "r", stdin);
    freopen("dock.out", "w", stdout);
    readlld(n);
    readlld(m);

    for (long long i = 1; i <= m; i++) {
        readlld(a[i]);
        readlld(b[i]);
        sss[++ks] = a[i];
        sss[++ks] = b[i];
        ans       = ans + abs(a[i] - b[i]);
    }
    // long long ans = 100000000000;
    //  for (long long i = 1; i <= n; i++) {
    //  long long sum = 0;
    //  for (long long j = 1; j <= m; j++) {
    //  sum += len_s(i, j);
    // }
    // if (sum < ans) {
    // ans = sum;
    // x   = i;
    // }
    // }
    sort(sss + 1, sss + ks + 1);
    int bet = m;

    for (int i = 1; i <= m; i++) {
        ans += abs(sss[bet] - a[i]) + abs(sss[bet] - b[i]);
    }
    cout << sss[bet] << ' ' << ans;

    // x = m;
    // cout << x << ' ' << ans;
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
