#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int prime(long long a)
{
    for(int i=2; i<=sqrt(a); i++)
    {
        if(a%i==0)
        {
            return false;
        }
    }
    return true;
}
long long n;
int main()
{
    cin>>n;
    if(prime(n))
    {
        cout<<0;
        return 0;
    }
    cout<<1;
    return 0;
}