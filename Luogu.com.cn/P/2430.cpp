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

int wky[5000 + 10];
int wang[5000 + 10];
int a, b, n, m;
int t;
int p[5000 + 10], q[5000 + 10];
int f[5000 + 10];
int main() {
    std::ios::sync_with_stdio(false);
    // freopen("main.in", "r", stdin);
    // freopen("main.out", "w", stdout);
    readd(a);
    readd(b);
    readd(m);
    readd(n);
    for (int i = 1; i <= n; i++) {
        readd(wang[i]);
        wky[i] = wang[i] * (b / a);
    }
    for (int i = 1; i <= m; i++) {
        readd(p[i]);
        readd(q[i]);
    }
    readd(t);
    for (int i = 1; i <= m; i++) {
        for (int j = t; j >= wky[p[i]]; j--) {
            f[j] = max(f[j], f[j - wky[p[i]]] + q[i]);
        }
    }
    cout << f[t];
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}