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

int n, m;
vector<int> b[2000 + 10];
vector<int> id;

int main() {
    std::ios::sync_with_stdio(false);
    // freopen("group.in", "r", stdin);
    // freopen("group.out", "w", stdout);

    readd(n);
    readd(m);

    for (int i = 1; i <= n; i++) {
        int k1, k2;
        readd(k1);
        readd(k2);
        b[k2].push_back(k1);
        id.push_back(id);
    }

    // fclose(stdin);
    // fclose(stdout);
    return 0;
}