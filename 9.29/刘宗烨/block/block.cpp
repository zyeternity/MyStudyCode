#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;
#define Max 40000 + 10

ll n, a[60000], ans;

int main() {
    freopen("block.in", "r", stdin);
    freopen("block.out", "w", stdout);
    map<ll, ll> m;
    ll ma, mi;

    cin >> n;
    for (int i = 1, x; i <= n; ++i) {
        cin >> x;
        ++m[x];
        ma = max(ma, (ll)x);
        mi = min(mi, (ll)x);
    }
    for (int i = mi; i <= ma + n; ++i) {
        if (m[i] > 1) {
            ans += (m[i] - 1);
            m[i + 1] += (m[i] - 1);
        }
    }
    cout << ans << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}