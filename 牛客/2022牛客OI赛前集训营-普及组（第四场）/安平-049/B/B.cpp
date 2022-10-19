#include <bits/stdc++.h>
using namespace std;

#define max_n (100005+10)

long long n;
long long ans = 1e18;
long long jin[max_n],fang[max_n];

int main() {
    
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);

    jin[0] = fang[0] = 0;

    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
    {
        char c;
        // scanf("%c",&c);
        cin>>c;
        jin[i] = jin[i- 1];
        fang[i] = fang[i- 1];
        if (c == '1')fang[i] += i;
        else jin[i] += i;
    }
    
    for (int i = 0; i <= n; i++)
    {
        ans = min(ans,abs((long long)(jin[i] - fang[n] + fang[i])));
    }

    printf("%lld\n", ans);

    fclose(stdin);
    fclose(stdout);

    return 0;
}