#include <bits/stdc++.h>
using namespace std;
string num;
int main(){
    cin>>num;
    while(num.length()>1){
        long long sum = 0;
        for(unsigned long long i=0;i<num.length();i++){
            sum += (num[i]-'0');
        }
        num = to_string(sum);
    }
    cout<<num;
    return 0;
}