#include <bits/stdc++.h>
using namespace std;
int n;
int len[1000000+10];
int jl[1000000+10];
int minn;
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>len[i];
    sort(len,len+n,[&](int a,int b){return a < b;});
    for(int i=0;i<n-1;i++){
        jl[i] = len[i+1] - len[i];
        //cout<<jl[i]<<' ';
    }
    //cout<<endl;
    minn = max(jl[0],jl[n-1-1]);
    for(int i=1;i<n-1;i++){
        //cout<<max(jl[i-1],jl[i])<<' ';
        minn = max(
            minn,
            max(jl[i-1],jl[i])
        );
    }
    //cout<<endl;
    cout << minn << endl;
    return 0;
}