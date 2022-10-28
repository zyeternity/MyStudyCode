#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin>>s;
    cin>>t;
    int ans = 0;
    int tlen = t.length(),slen = s.length();
    for(int i=0;i<=tlen-slen;i++){
        bool ok = true;
        for(int j=0;j<slen;j++){
            if(t[i+j] != s[j]){
                //cout<<t[i+j] <<"!="<<s[j]<<endl;
                ok = false;
                break;
            }
        }
        if(ok){
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}