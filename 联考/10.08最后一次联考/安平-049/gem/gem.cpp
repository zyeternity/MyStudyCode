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

long long n, lim;
long long a, b, c, d;

int main() {

    freopen("gem.in","r",stdin);
    freopen("gem.out","w",stdout);

    Cin >> n >> lim;
    Cin >> a >> b >> c >> d;
    long long n_a, n_b, n_c, n_d;
    for (long long i = 0; i < n; i++) {
        int k;
        Cin >> k;
        switch (k) {
        case 1:
            n_a = min(lim, a + 50);
            n_b = max((long long)0, b - a);
            n_c = min(lim, c + 20);
            n_d = min(lim, d + 20);
            break;
        case 2:
            n_a = max((long long)0, a - b);
            n_b = min(lim, (long long)((b * 1.0) * 1.3));
            n_c = min(lim, c + 20);
            n_d = d / 2;
            break;
        case 3:
            n_a = min(lim, (long long)ceil((a * 1.0) * 1.145));
            n_b = min(lim, b + c);
            n_c = min(lim, c * 2);
            n_d = d / 2;
            break;
        case 4:
            n_a = min(lim, a + d);
            n_b = max((long long)0, b - d);
            n_c = c / 2;
            n_d = min(lim, (long long)ceil((d * 1.0) * 1.8));
            break;
        default:
            break;
        }
        a = n_a;
        b = n_b;
        c = n_c;
        d = n_d;
        //printf("%lld -> %lld %lld %lld %lld\n", i, a, b, c, d);
    }
    printf("%lld %lld %lld %lld\n", a, b, c, d);
    fclose(stdin);
    fclose(stdout);

    return 0;
}