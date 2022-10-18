/*#include <bits/stdc++.h>
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

long long ans = 1;
long long now = 1;
long long to;

int main() {
    // freopen("calc.in","r",stdin);
    // freopen("calc.out","w",stdout);
    Cin >> to;
    bool howto = false;
    while (true) {
        if (now == to)
            break;
        if (now * now >= now + 1) {
            if (now * now <= to) {
                howto = true;
            } else {
                howto = false;
            }
        } else {
            howto = false;
        }
        if (howto) {
            now *= now;

        } else {
            now++;
        }
        ans++;
    }
    Cout << ans;
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
*/
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

long long ans = 0;
long long now = 0;

int main() {

    // freopen("calc.in","r",stdin);
    // freopen("calc.out","w",stdout);

    Cin >> now;

    while (true) {
        long long s_now = sqrt(now);
        if (now == s_now * s_now && s_now > 1) {
            now = s_now;
            ans++;
        } else {
            now--;
            ans++;
        }
        if(now == 0){
            break;
        }
    }
    Cout << ans;
    printf("\n");
    // fclose(stdin);
    // fclose(stdout);

    return 0;
}