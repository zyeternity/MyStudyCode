#include <bits/stdc++.h>
using namespace std;

// struct main{
//     int a;
//     bool operator==(const main b) const
//     {
//         return this->a == b.a;
//     }
// };

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
int p[1000000];
int ans     = 0;
int add_day = 0;
int main() {
    std::ios::sync_with_stdio(false);
    freopen("goods.in", "r", stdin);
    freopen("goods.out", "w", stdout);
    readd(n);
    readd(x);
    readd(k);
    for (int i = 0; i < n; i++) {
        readd(p[i + 1]);
    }

    sort(p + 1, p + n + 1, [&](int a, int b) { return a < b; });

    while (true) {
        int day_x = x;
        if (p[1] + add_day * k > x) {
            break;
        }
        for (int i = 1; i <= n; i++) {
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
