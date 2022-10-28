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
        int cut = 0;
        while (tmp) {
            F[cut++] = tmp % 10 + '0';
            tmp /= 10;
        }
        while (cut)
            putchar(F[--cut]);
    }
} Cout;
} // namespace IO_ios

using namespace IO_ios;
#define int long long

#define maxsize 160000

int k, x, y;

int sum;

int f[maxsize+10];

int allww, c, w[100100], v[100100];

signed main() {
    for (int i = 1; i < maxsize;i++) {
        f[i] = 1e9;
    }
    

    Cin >> k >> x >> y;

    for (int i = 1; i <= k; i++) {
        Cin >> allww >> c;
        int cut = 1;
        while (c >= cut) {
            v[sum+1] = cut * y;
            w[sum+1] = cut * allww;
            c = c - cut;
            cut = cut * 2;
            sum++;
        }
        if (c) {
            v[sum+1] = c * y;
            w[sum+1] = c * allww;
        }else{
            sum-= 1;
        }
        sum++;
    }

    for (int i = 1; i <= sum; i++)
        for (int j = maxsize; j >= w[i]; j--)
            f[j] = min(f[j], f[j - w[i]] + v[i]);
    
    int ans = 1e9;

    for (int i = x; i <= maxsize; i++)
        if (f[i] != 1e9)
            ans = min(ans, f[i] + i);
    
    cout << ans << endl;
    
    return 0;
}
