#include <bits/stdc++.h>
using namespace std;
#define mod (1000000000 + 7)
#define int long long
int ans;

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
inline int mygcd(int a, int b) { return b > 0 ? mygcd(b, a % b) : a; }

int n, p[10000000 + 10];
int check(int i) {
    if (i + 1 == n)
        return (i + 1) * p[i];
    return mygcd((i + 1) * p[i], check(i + 1));
}

signed main() {
    std::ios::sync_with_stdio(false);
    freopen("gcd.in", "r", stdin);
    freopen("gcd.out", "w", stdout);
    n = read();
    for (int i = 0; i < n; i++)
        p[i] = i + 1; //初始化
    do {
        // for(int i = 0;i<n;i++){
        //     cout<<p[i]<<' ';
        // }
        // cout<<'\n';
        if (check(0) == 1)
            ans++;
    } while (next_permutation(p, p + n));
    write(ans % mod);
    fclose(stdin);
    fclose(stdout);
    return 0;
}