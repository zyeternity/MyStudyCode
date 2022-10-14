#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","w",stdout);
    srand(time(0));
    cout<<1<<endl;
    int n = rand()%5000+1;
    while(n == 0)n = rand()%5000+1;
    cout<<n<<endl;
    for(int i = 0;i<n;i++){
        int k = rand()%20;
        while(k == 0)k = rand()%20;
        for(int i = 0;i<k;i++){
            cout<<char('a' + (rand()%(int)('z' - 'a')));
        }
        cout<<endl;
    }
    int t = rand()%100;
    while(t == 0)t = rand()%100;
    for(int i = 0;i<t;i++){
        cout<<char('a' + (rand()%(int)('z' - 'a')));
    }
    return 0;
}