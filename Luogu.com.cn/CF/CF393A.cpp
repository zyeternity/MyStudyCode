#include <bits/stdc++.h>
using namespace std;
unordered_map<char,int> c;
int main(){
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        c[s[i]]++;
    }
    printf("%d\n",min((c['n']-1)/2,min(c['i'],min(c['t'],c['e']/3))));
    return 0;
}
