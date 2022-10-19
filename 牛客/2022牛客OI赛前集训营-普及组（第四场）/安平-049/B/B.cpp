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

#define max_n (100005+10)

long long n,x,y;
long long ans = 1e18;
long long jin[max_n],fang[max_n];

int main() {
    
    // freopen("B.in","r",stdin);
    // freopen("B.out","w",stdout);

    Cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char c = getchar();
        jin[i] = jin[i- 1];
        fang[i] = fang[i- 1];
        if (c == '1')fang[i] += i;
        else jin[i] += i;
    }
    
    for (int i = 0; i <= n; i++)
    {
        ans = min(ans,(long long)(jin[i],fang[n] - fang[i]));
    }

    Cout << ans;

    printf("\n");
    // fclose(stdin);
    // fclose(stdout);

    return 0;
}