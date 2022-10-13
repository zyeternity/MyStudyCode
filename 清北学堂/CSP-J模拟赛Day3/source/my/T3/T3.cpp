#include <bits/stdc++.h>

using namespace std;

int n,k;
int true_a,false_a;
int main() {
    //freopen("T3.in","r",stdin);
    //freopen("T3.out","w",stdout);
    
    cin>>n>>k;
    for(int i = 0;i<n;i++){
        char t;
        cin>>t;
        if(t == '1')true_a ++;
        else false_a++;
    }
    cout<<n - (k - false_a);
    
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}