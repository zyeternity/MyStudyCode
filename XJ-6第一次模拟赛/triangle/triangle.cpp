#include <bits/stdc++.h>
using namespace std;

long long a,b,c;
int main() {

    // freopen("triangle.in","r",stdin);
    // freopen("triangle.out","w",stdout);

    cin>>a>>b>>c;
    if(a+b<=c||a+c<=b||b+c<=a){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }

    // fclose(stdin);
    // fclose(stdout);

    return 0;
}