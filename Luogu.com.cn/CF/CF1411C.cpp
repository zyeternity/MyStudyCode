#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,r,c;
        cout<<max(r-1+c-1,max(n-r+c-1,max(r-1+m-c,n-r+m-c)))<<endl;
    }
}
