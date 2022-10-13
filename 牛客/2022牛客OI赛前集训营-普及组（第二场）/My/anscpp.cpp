#include <bits/stdc++.h>
using namespace std;

namespace IO {
inline void read(int &k) {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x  = x * 10 + (ch - '0');
        ch = getchar();
    }
    k = x * w;
    return;
}
inline void write(int x) {
    static int sta[35];
    int top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top)
        putchar(sta[--top] + 48);
}

inline void read(long long &k) {
    long long x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x  = x * 10 + (ch - '0');
        ch = getchar();
    }
    k = x * w;
    return;
}
inline void write(long long x) {
    static long long sta[35];
    long long top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top)
        putchar(sta[--top] + 48);
}

inline void read(unsigned long long &k) {
    unsigned long long x = 0;
    char ch              = 0;
    while (ch < '0' || ch > '9') {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x  = x * 10 + (ch - '0');
        ch = getchar();
    }
    k = x;
    return;
}
inline void write(unsigned long long x) {
    static unsigned long long sta[35];
    long long top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top)
        putchar(sta[--top] + 48);
}
} // namespace IO

int main() {
    std::ios::sync_with_stdio(false);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    // Your Code

    // fclose(stdin);
    // fclose(stdout);
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int x[N],y[N],p[2*N];
int n,m,cnt;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // freopen("T3simple.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x[i]>>y[i];
        p[++cnt]=x[i];
        p[++cnt]=y[i];
    }
    sort(p+1,p+1+cnt);
    int sum1=0,sum2=0;
    int f1=p[cnt/2];
    int f2=p[cnt/2+1];
    //1
    for(int i=1;i<=m;i++)
    {
        sum1+=abs(f1-x[i])+abs(x[i]-y[i])+abs(y[i]-f1);
    }
    //2
    for(int i=1;i<=m;i++)
    {
        sum2+=abs(f2-x[i])+abs(x[i]-y[i])+abs(y[i]-f2);
    }
    if(sum1<=sum2)
    {
        cout<<f1<<" "<<sum1<<"\n";
    }
    else
    {
        cout<<f2<<" "<<sum2<<"\n";
    }

    return 0;
}
*/
/*
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int pre[N],pre1[N],suf[N],suf1[N];
int pos=-1,ans=1e18;
int n,m,a,b,sum;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        pre[a-1]+=2;
        suf[b+1]+=2;
        sum+=(b-a)*2;
    }
    for(int i=n;i>=1;i--)
    {
        pre[i]+=pre[i+1];
        pre1[i]=pre1[i+1]+pre[i];
    }
    for(int i=1;i<=n;i++)
    {
        suf[i]+=suf[i-1];
        suf1[i]=suf1[i-1]+suf[i];
        if(suf1[i]+pre1[i]<ans)
        {
            pos=i;
            ans=suf1[i]+pre1[i];
        }
    }
    cout<<pos<<" "<<ans+sum<<"\n";
    return 0;
}
*/