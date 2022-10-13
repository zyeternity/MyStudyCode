#include <bits/stdc++.h>
using namespace std;

inline int read() {
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

int n, B, x, y, ans = 0;

int main() {
    std::ios::sync_with_stdio(false);
    freopen("recursion.in", "r", stdin);
    freopen("recursion.out", "w", stdout);
    n       = read();
    B       = read();
    x       = read();
    y       = read();
    int now = B + x;
    ans     = now;
    for (int i = 1; i < n; i++) {
        if (ans - y >= B) {
            now -= y;
        } else {
            now += x;
            ans += x;
        }
    }
    write(ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}