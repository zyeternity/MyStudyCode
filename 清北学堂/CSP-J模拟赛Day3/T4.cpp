#include <bits/stdc++.h>
using namespace std;
int n;
int num[100000 * 2 + 10];
int maxs = 0,max_id = 10000000;
int main() {
    cin >> n;
    for (int i = 0,k; i < n; i++) {
        cin>>k;
        num[k] ++;
        if(num[k] == maxs)max_id = min(k,max_id);
        if(num[k] > maxs){
            max_id = k;
            maxs = num[k];
        }
        cout<<max_id<<endl;
    }
    return 0;
}