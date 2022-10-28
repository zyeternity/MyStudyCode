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
        _Tp tmp = x >= 0 ? x : (putchar('-'), -x);
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

int n, m;

int cut = 0;
int a[1000 + 10];

struct kkk {
    int a[1000 + 10];
    int len;
    int pn;
} tim;

#define debug false

int main() {
    // freopen("cauchy,cpp.in","r",stdin);
    // freopen("cauchy,cpp.out","w",stdout);
    Cin >> n >> m;
    for (int i = 0; i < n; i++) {
        Cin >> a[i];
    }
    queue<kkk> que;
    que.push(tim);
    int ans = 1e8;
    kkk pi;
    while (!que.empty()) {
        pi = que.front();
        que.pop();
        if (pi.len == m) {
            int nmax = 0;
            for (int i = 0; i < pi.len - 1; i++) {
                if (debug)
                    cout << pi.a[i] << ' ';
                nmax = max(nmax, abs(pi.a[i] - pi.a[i + 1]));
            }
            if (debug)
                cout << pi.a[pi.len - 1] << '\t';
            if (debug)
                cout << nmax << endl;
            ans = min(ans, nmax);
            if (ans == 1 || ans == 0)
                break;
        }
        for (int i = pi.pn; i < n - (m - pi.pn) + 1; i++) {
            pi.a[pi.len] = a[i];
            // tim.a = pi.a;
            copy(begin(pi.a), end(pi.a), begin(tim.a));
            tim.len = pi.len + 1;
            tim.pn  = i + 1;
            que.push(tim);
        }
    }
    Cout << ans;
    // fclose(stdin);
    // fclose(stdout);















    return 0;
}