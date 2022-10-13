#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 4e4 + 5;
int Q, n, d[N], s[N], sz[N], f[N], ans, sum[N], sq[N];
vector<int> g[N];
void dfs(int x, int fa) {
    sz[x] = 1;
    for (int i : g[x]) {
        if (i ^ fa) {
            d[i] = d[x] + 1;
            dfs(i, x);
            sz[x] += sz[i];
            s[x] += s[i] + sz[i];
        }
    }
}
void cr(int x, int fa) {
    for (int i : g[x]) {
        if (i ^ fa) {
            sum[i] = sum[x] + n - 2 * sz[i];
            sq[i] = sq[x] + n - 2 * (s[i] + sz[i]) + 2 * (sum[x] - s[i] - sz[i]);
            cr(i, x);
        }
    }
}
signed main() {
    scanf("%lld", &Q);
    while (Q--) {
        memset(d, 0, sizeof(d));
        memset(s, 0, sizeof(s));
        memset(g, 0, sizeof(g));
        memset(sz, 0, sizeof(sz));
        memset(sum, 0, sizeof(sum));
        memset(sq, 0, sizeof(sq));
        scanf("%lld", &n);
        ans = 1e18;
        for (int i = 1, u, v; i < n; ++i) {
            scanf("%lld%lld", &u, &v);
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        dfs(1, 0);
        sum[1] = s[1];
        for (int i = 1; i <= n; ++i) {
            sq[1] += d[i] * d[i];
        }
        cr(1, 0);
        for (int i = 1; i <= n; ++i) {
            ans = min(ans, n * sq[i] - sum[i] * sum[i]);
        }
        printf("%lld\n", ans);
    }
}