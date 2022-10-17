#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1000000007;
int n, m, t;
ll f[100005], g[100005], ans[100005];
int head[1000005], x[1000005], nt[1000005], tot;
int head1[400005], x1[400005], nt1[400005], tot1, mx;
int d[100005];
bool vis[100005];
void link(int a, int b) {
    nt[++tot] = head[a];
    x[tot] = b, head[a] = tot;
}
void link1(int a, int b) {
    nt1[++tot1] = head1[a];
    x1[tot1] = b, head1[a] = tot1;
}
void dfs(int xx, int f) {
    d[xx] = d[f] + 1;
    link1(d[xx], xx);
    mx = max(d[xx], mx);
    for (int i = head[xx]; i; i = nt[i]) {
        if (x[i] == f)
            continue;
        dfs(x[i], xx);
    }
}
int main() {
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &ans[i]);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        link(a, b);
        link(b, a);
    }
    dfs(1, 0);
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        link(a, b);
        link(b, a);
    }
    for (int i = 1; i <= t; i++) {
        int tp, u;
        ll k;
        scanf("%d%d%lld", &tp, &u, &k);
        if (tp == 1) {
            f[u] += k;
            f[u] %= mod;
        } else {
            g[u] += k;
            g[u] %= mod;
        }
    }

    // 从底往上
    for (int i = mx; i >= 1; i--) {
        for (int j = head1[i]; j; j = nt1[j]) {
            int pos = x1[j];
            for (int op = head[pos]; op; op = nt[op]) {
                if (d[x[op]] >= d[pos])
                    continue;
                f[x[op]] += f[pos];
                f[x[op]] %= mod;
            }
        }
    }
    // 从上往底
    for (int i = 1; i <= mx; i++) {
        for (int j = head1[i]; j; j = nt1[j]) {
            int pos = x1[j];
            for (int op = head[pos]; op; op = nt[op]) {
                if (d[x[op]] <= d[pos])
                    continue;
                g[x[op]] += g[pos];
                g[x[op]] %= mod;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%lld ", (ans[i] + f[i] + g[i]) % mod);
    }
    return 0;
}