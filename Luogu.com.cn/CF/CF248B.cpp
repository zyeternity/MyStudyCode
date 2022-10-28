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

int main() {

    // freopen("CF248B.in","r",stdin);
    // freopen("CF248B.out","w",stdout);
    int n;
    Cin>>n;
    if(n == 1|| n == 2)cout<<-1;
    else{
        if(n == 3)cout<<210;
        else{
            cout<<1;
            for (int i = 0; i < n-4; i++)
            {
                cout<<0;
            }
            int ans = 50;
            for (size_t i = 0; i < n-4; i++)
            {
                ans = ans*10;
                ans %=210;
            }
            printf("%03d\n",ans);
            
            
        }
    }

    // fclose(stdin);
    // fclose(stdout);

    return 0;
}