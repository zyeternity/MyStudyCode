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
int n,k;
int a[60];
long long ans = 0;
int main() {

    // freopen("P3867.in","r",stdin);
    // freopen("P3867.out","w",stdout);

    Cin>>n>>k;
    for (int i = 1; i <= n; i++)
    a[i] = i;
    do{
        bool flag = true;
        for(int i = 1; i < n; i++){
            if(abs(a[i] - a[i+1]) > k){
                flag = false;
                break;
            }
        }
        if(flag){
            ans++;
            ans %= 1000000007;
        }
    }while(next_permutation(a+1,a+n+1));
    
    Cout<<ans;
    // fclose(stdin);
    // fclose(stdout);

    return 0;
}