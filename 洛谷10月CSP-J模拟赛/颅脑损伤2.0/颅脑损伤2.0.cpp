#include <bits/stdc++.h>
using namespace std;

namespace IO_ios {
#define MAXN 100
struct ios_in {
    template <typename _Tp> inline ios_in &operator>>(_Tp &x) {
        char ch = getchar(), sgn = 0;
        x = 0;
        while (ch ^ '-' && !isdigit(ch))
            ch = getchar();
        if (ch == '-')
            ch = getchar(), sgn = 1;
        while (isdigit(ch))
            x = x * 10 + ch - '0', ch = getchar();
        if (sgn)
            x = -x;
        return *this;
    }
} Cin;

struct ios_out {
    template <typename _Tp> inline void operator<<(_Tp &x) {
        char F[MAXN];
        _Tp tmp = x > 0 ? x : (putchar('-'), -x);
        int cnt = 0;
        while (tmp) {
            F[cnt++] = tmp % 10 + '0';
            tmp /= 10;
        }
        while (cnt)
            putchar(F[--cnt]);
    }
} Cout;
} // namespace IO_ios

using namespace IO_ios;

int n;

#define blackl false
#define redl true
struct xd {
    int l, r;
    bool color;
} a[3000 + 10];

long long ans = 1e18;

long long sum = 0;

void dfs(int now) {
    if (now == n) {
        ans = min(ans, sum);
        cout << sum << endl;
        return;
    }
    if (now == 0) {
        a[now].color = blackl;
        dfs(now + 1);
        a[now].color = redl;
        sum += a[now].r - a[now].l;
        dfs(now + 1);
    } else {
        //相交
        if (a[now - 1].r >= a[now].l) {
            if (a[now - 1].color == blackl) {
                if (now == 1) { // 只能走红色
                    a[now].color = redl;
                    sum += a[now].r - a[now].l;
                    dfs(now + 1);
                    sum -= a[now].r - a[now].l;
                } else {
                    // di now - 1已经与红色相连
                    if (a[now - 2].color == redl &&
                        a[now - 2].r >= a[now - 1].l) {

                        a[now].color = blackl;
                        dfs(now + 1);

                        a[now].color = redl;
                        sum += a[now].r - a[now].l;
                        dfs(now + 1);
                        sum -= a[now].r - a[now].l;
                    } else {
                        a[now].color = redl;
                        sum += a[now].r - a[now].l;
                        dfs(now + 1);
                        sum -= a[now].r - a[now].l;
                    }
                }
            } else {
                a[now].color = blackl;
                dfs(now + 1);
            }
        } else {
            a[now].color = blackl;
            dfs(now + 1);

            a[now].color = redl;
            sum += a[now].r - a[now].l;
            dfs(now + 1);
            sum -= a[now].r - a[now].l;
        }
    }
}

int main() {

    // freopen("颅脑损伤2.0.in","r",stdin);
    // freopen("颅脑损伤2.0.out","w",stdout);

    Cin >> n;
    for (int i = 0; i < n; i++) {
        Cin >> a[i].l;
        Cin >> a[i].r;
    }
    sort(a, a + n, [&](xd a, xd b) { return a.l < b.l; });
    dfs(0);
    Cout << ans;
    // fclose(stdin);
    // fclose(stdout);

    return 0;
}