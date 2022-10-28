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

unordered_map<int,bool>have;

int main() {

    // freopen("1059.in","r",stdin);
    // freopen("1059.out","w",stdout);
    int n;
    cin >> n;
    int s[100];
    int cut = 0;
    for (int i = 0;i<n;i++){
        int k;
        cin>>k;
        if(!have[k]){
            s[cut++] = k;
        }
        have[k] = true;
    }
    cout<<cut<<endl;
    sort(s,s+cut,[&](int a,int b){return a<b;});
    for (int i = 0;i<cut;i++)
        cout<<s[i]<<" ";
    // fclose(stdin);
    // fclose(stdout);

    return 0;
}