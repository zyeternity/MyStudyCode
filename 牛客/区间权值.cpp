#include <bits/stdc++.h>
using namespace std;
int n;
int la[100000+10];
int w[100000+10];
int dp[100000+10];
long long ans;
long long f(int l,int r){
    return ((la[r]-la[l-1]) * w[r-l+1])%1000000007;
}
int main(){
    cin>>n;
    for(int i = 1,k;i<=n;i++){
        cin>>k;
        la[i] = (la[i-1] + k)%1000000007;
    }
    for(int i = 1;i<=n;i++)cin>>w[i];
    for(int i = 1;i<=n;i++){
        dp[i]=dp[i-1] + f(i,i);
    }
    for(int l = 1;l<=n;l++){
        for(int r = l;r<=n;r++){
            ans = ans+dp[r]-dp[l-1];
            ans %= 1000000007;
        }
    }
    cout<<ans;
    return 0;
}