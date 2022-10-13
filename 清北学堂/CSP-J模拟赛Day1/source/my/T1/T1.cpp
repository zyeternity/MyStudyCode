#include <bits/stdc++.h>
using namespace std;

int t, n, ans;
int a[1005], b[1005];

int main() {

    cin >> t;

    while (t--) {
        cin >> n;
        ans = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        sort(a, a + n, [&](int i, int j) { return i < j; });
        sort(b, b + n, [&](int i, int j) { return i > j; });

        for (int i = 0; i < n; i++) {
            ans += a[i] * b[i];
        }

        cout << ans << endl;
    }

    return 0;
}