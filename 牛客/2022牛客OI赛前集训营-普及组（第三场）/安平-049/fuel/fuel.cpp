#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, k, Q, t;
int shiji;
int ans = 0;

signed main() {
    std::ios::sync_with_stdio(false);
    freopen("fuel.in", "r", stdin);
    freopen("fuel.out", "w", stdout);

    cin >> n >> m >> k >> Q >> t;

    if (n * k > m) {
        shiji = m / k;
    } else {
        shiji = n;
    }
    // cout << "shiji=" << shiji << endl;
    m -= shiji * k;
    // int ping = shiji;
    // int dou  = m % shiji;
    // cout << "m=" << m << endl;
    ans += min((k + (m / shiji)) * t, Q) * (shiji - (m % shiji));
    // cout << "ans now=" << ans << endl;
    ans += min((k + (m / shiji) + 1) * t, Q) * (m % shiji);
    cout << ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}