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
int p[1000000 + 10];
int ans     = 0;
int add_day = 0;
int dp[1000000 + 10];
int min_p = 1e9;

int main() {
    std::ios::sync_with_stdio(false);
    freopen("goods.in", "r", stdin);
    freopen("goods.out", "w", stdout);
    readd(n);
    readd(x);
    readd(k);
    
    for (int i = 0; i < n; i++) {
        readd(p[i + 1]);
        min_p = min(min_p,p[i+1]);
    }


    while (true) {
        int day_x = x;
        if (min_p + add_day * k > x) {
            break;
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            for (int j = day_x; j >= ((k * add_day) + p[i]); j--) {
                dp[j] = max(dp[j], dp[j - p[i] - (k * add_day)] + 1);
            }
        }
        add_day++;
        ans += dp[x];
    }

    write(ans);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
