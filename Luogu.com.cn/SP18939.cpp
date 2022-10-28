#include <bits/stdc++.h>
using namespace std;
unsigned arr[5000000];

void randomize(unsigned a,unsigned b,unsigned mod)
{
    for( int i=0 ; i<5000000 ; i++ )
    {
        a = 31014 * (a & 65535) + (a >> 16);
        b = 17508 * (b & 65535) + (b >> 16);
        arr[i] = ((a << 16) + b) % mod;
    }
}
int main(){
    unsigned a,b,mod,k;
    cin>>a>>b>>mod>>k;
    randomize(a,b,mod);
    nth_element(arr,arr + k - 1,arr+5000000);
    cout<<arr[k-1];
    return 0;
}