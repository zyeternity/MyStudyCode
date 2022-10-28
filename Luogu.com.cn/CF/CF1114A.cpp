#include<bits/stdc++.h>
using namespace std;
int main(){
    int need1, need2, need3;
    int have1, have2, have3;
    cin>>need1>>need2>>need3>>have1>>have2>>have3;
    if(have1<need1){
        cout<<"NO"<<endl;
        return 0;
    }
    have1-=need1;
    need2 -=have1;
    if(need2 >have2){
        cout<<"NO"<<endl;
        return 0;
    }
    have2 -= need2;
    need3 -= have2;
    if(have3 < need3){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    return 0;
}