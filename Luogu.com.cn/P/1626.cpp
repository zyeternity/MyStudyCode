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

int n;
int a[100000 + 10];
int k;
int cs[100000 + 10];
int cut = 0;
int ans = 0;
int main() {
    std::ios::sync_with_stdio(false);
    // freopen("main.in", "r", stdin);
    // freopen("main.out", "w", stdout);
    readd(n);
    readd(k);
    for (int i = 0; i < n; i++) {
        readd(a[i]);
    }
    sort(a, a + n);
    for (int i = 0; i < n - 1; i++) {
        cs[cut++] = abs(a[i] - a[i + 1]);
    }
    sort(cs, cs + cut, [&](int a, int b) { return a < b; });

    for (int i = 0; i < k; i++) {
        ans += cs[i];
    }
    cout << ans;
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}