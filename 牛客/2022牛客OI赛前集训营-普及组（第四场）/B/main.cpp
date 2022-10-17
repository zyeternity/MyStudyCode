#include <cmath>
#include <iostream>
#define int long long
using namespace std;

int c[100005], s[100005];

signed main() {
    int n, ans;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%1d", &k);
        c[i] = c[i - 1] + i * (k == 0);
        s[i] = s[i - 1] + i * (k == 1);
    }
    ans = s[n];
    for (int i = 1; i <= n; i++) {
        int sum1 = c[i], sum2 = s[n] - s[i];
        ans = min(ans, abs(sum1 - sum2));
    }
    cout << ans << endl;
    return 0;
}