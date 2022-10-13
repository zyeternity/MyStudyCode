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

int main() {
    std::ios::sync_with_stdio(false);
    // freopen("main.in", "r", stdin);
    // freopen("main.out", "w", stdout);

    int n;
    readd(n);
    cout << n;

    // fclose(stdin);
    // fclose(stdout);
    return 0;
}