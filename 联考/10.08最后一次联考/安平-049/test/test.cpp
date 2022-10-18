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

#define max_n 100000
#define mod_t 1000000007

int n, m, k;
map<int,bool> cant[max_n];
int now_time[max_n];
vector<int> t_have[10000000];

long long ans = 0;
//           去判断第几个
void dfs(int now){
    if(now==n){
        ans = (ans+1)%mod_t;
        return;
    }
    for(int i=1;i<=k;i++){// 枚举可选时间点

        bool canuse = true;

        for(int j=0;j<t_have[i].size();j++){
            if(cant[t_have[i][j]][now]){
                canuse = false;
                break;
            }
        }
        if(!canuse)continue;
        
        t_have[i].push_back(now);
        dfs(now + 1);
        t_have[i].pop_back();
    }
}

int main() {

    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);

    Cin >> n >> m >> k;

    while (m--) {
        int x,y;
        Cin >> x >> y;
        cant[x][y] = true;
        cant[y][x] = true;
    }
    
    dfs(0);

    Cout << ans ;
    printf("\n");
    fclose(stdin);
    fclose(stdout);

    return 0;
}