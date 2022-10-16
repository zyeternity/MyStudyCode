#include <bits/stdc++.h>
using namespace std;
#define int long long

inline int readd() {
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
    return x * w;
}

inline void write(int x) {
    static int sta[35];
    int top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top)
        putchar(sta[--top] + 48);
}
int n, x, k;
vector<int> p;
int ans     = 0;
int add_day = 0;
signed main() {
    std::ios::sync_with_stdio(false);
    freopen("goods.in", "r", stdin);
    freopen("goods.out", "w", stdout);
    n = readd();
    x = readd();
    k = readd();
    for (int i = 0; i < n; i++) {
        p.push_back(readd());
    }

    sort(p.begin(), p.end());

    while (true) {
        int day_x = x;
        if (p[0] + add_day * k > x) {
            break;
        }
        for (int i = 0; i < n; i++) {
            if (p[i] + add_day * k > day_x) {
                break;
            }
            ans++;
            day_x -= (p[i] + add_day * k);
        }
        add_day++;
    }

    write(ans);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
