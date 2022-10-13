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

int f[50 + 10][400 + 10][400 + 10];
int m, v, n;
int vi[400 + 10], mi[400 + 10], ki[400 + 10];
int main() {
    std::ios::sync_with_stdio(false);
    // freopen("main.in", "r", stdin);
    // freopen("main.out", "w", stdout);
    readd(v);
    readd(m);
    readd(n);
    for (int i = 1; i <= n; i++) {
        readd(vi[i]), readd(mi[i]), readd(ki[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = v; j >= 1; j--) {
            for (int k = m; k >= 1; k--) {
                if (j >= vi[i] && k >= mi[i])
                    f[i][j][k] = max(f[i - 1][j][k],
                                     f[i - 1][j - vi[i]][k - mi[i]] + ki[i]);
                else
                    f[i][j][k] = f[i - 1][j][k];
                /*max(f[i][j][k], f[i][j - vi[i]][k - mi[i]] + ki[i]);*/
            }
        }
    }
    cout << f[n][v][m];
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}