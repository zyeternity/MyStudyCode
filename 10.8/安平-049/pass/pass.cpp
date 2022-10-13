#include <bits/stdc++.h>
using namespace std;
int read() {
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
int n, m, k, q;
int a_s[1000 + 10], b_s[1000 + 10];
int ans   = 0;
bool ztj_ = 0;
int pa = 0, pb = 0;
int main() {
    freopen("pass.in", "r", stdin);
    freopen("pass.out", "w", stdout);
    n = read();
    m = read();
    k = read();
    q = read();
    for (int i = 1; i <= n; i++) {
        a_s[i] = read();
    }
    for (int i = 1; i <= n; i++) {
        b_s[i] = read();
    }
    while (pa < n || pb < n){
        int pa_last, pb_last,ka,kb;
        do {
            ka = pa_last = pa, kb = pb_last = pb;
            while ((a_s[pa + 1] - b_s[pb] <= q || pb == n) && ka < n) {
                if (a_s[pa + 1] - a_s[pa] > m && ztj_)
                    break;
                pa++;
            }
            while ((b_s[pb + 1] - a_s[pa] <= q || pa == n) && pb < n) {
                if (b_s[pb + 1] - b_s[pb] > m && !ztj_)
                    break;
                pb++;
            }
        } while (pa_last != pa || pb_last != pb);

        if (a_s[pa + 1] - a_s[pa] > m) {
            if (ztj_) {
                ans++;
                ztj_ = 0;
                pa++;
            }
        } else if (b_s[pb + 1] - b_s[pb] > m) {
            if (!ztj_) {
                ans++;
                ztj_ = 1;
                pb++;
            }
        }
    }
    write(ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}