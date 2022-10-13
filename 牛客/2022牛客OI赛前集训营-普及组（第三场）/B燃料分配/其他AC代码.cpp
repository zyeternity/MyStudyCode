#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k, Q, t, u, v, w, c;
signed main() {
    scanf("%lld%lld%lld%lld%lld", &n, &m, &k, &Q, &t);
    if (m < n * k) {
        u = m / k;
        v = m - u * k;
        w = v / u;
        c = v % u;
        printf("%lld", (u - c) * min(t * (k + w), Q) + c * min(t * (k + w + 1), Q));
    } else {
        u = m / n;
        v = m % n;
        printf("%lld", (n - v) * min(Q, u * t) + v * min(Q, (u + 1) * t));
    }
    return 0;
}