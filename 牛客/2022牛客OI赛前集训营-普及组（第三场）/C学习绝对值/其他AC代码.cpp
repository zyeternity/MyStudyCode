#include <bits/stdc++.h>
using namespace std;
#define N 500005
#define int long long
int fu2[N], two[N], fu1[N], one[N], n, a[N], ans;
signed main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        one[i] = one[i - 1] + (a[i] == 1);
        two[i] = two[i - 1] + (a[i] == 2);
        fu1[i] = fu1[i - 1] + (a[i] == -1);
        fu2[i] = fu2[i - 1] + (a[i] == -2);
    }
    for (int i = 1; i <= n; ++i) {
        int l = i, r = n, f = 0, f1 = 0;
        if (abs(a[i]) == 1) {
            while (l <= r) {
                int m = l + r >> 1;
                if (two[m] == two[i] && fu2[i] == fu2[m]) {
                    f = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            ans += f - i + 1;
            l = i, r = n, f = 0;
            while (l <= r) {
                int m = l + r >> 1;
                if (two[m] > two[i] && fu2[m] > fu2[i]) {
                    f = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            if (f) {
                ans += n - f + 1;
            }
        } else if (a[i] == 2) {
            while (l <= r) {
                int m = l + r >> 1;
                if (fu2[m] > fu2[i]) {
                    f = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            if (f) {
                ans += n - f + 1;
            }
            l = i, r = n;
            while (l <= r) {
                int m = l + r >> 1;
                if (one[i] == one[m] && fu1[i] == fu1[m]) {
                    f1 = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            ans += f1 - i + 1;
            if (f && f1 >= f) {
                ans -= f1 - f + 1;
            }
        } else {
            while (l <= r) {
                int m = l + r >> 1;
                if (two[m] > two[i]) {
                    f = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            if (f) {
                ans += n - f + 1;
            }
            l = i, r = n;
            while (l <= r) {
                int m = l + r >> 1;
                if (one[i] == one[m] && fu1[i] == fu1[m]) {
                    f1 = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            ans += f1 - i + 1;
            if (f && f1 >= f) {
                ans -= f1 - f + 1;
            }
        }
    }
    printf("%lld", ans);
}