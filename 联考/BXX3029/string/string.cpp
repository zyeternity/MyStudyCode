#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int t;
map<string,bool> chars_find;
string to;
int n;

bool can = false;


int main() {
    std::ios::sync_with_stdio(false);
    //freopen("string.in", "r", stdin);
    //freopen("string.out", "w", stdout);
    cin >> t;
    while (t--) {

        cin >> n;
        chars_find.clear();
        for(int i = 0;i<n;i++){
            string temp;
            cin>>temp;
            chars_find[temp] = true;
        }
        cin>>to;
        bool flag = true;
        while(flag){
            flag = false;
            if(to.length() == 0){
                break;
            }
            for(ull i = 1;i<=to.length();i++){
                if(chars_find[to.substr(0,i)]){
                    to = to.substr(i,to.length() - i);
                    //cout<<"delete over "<<to<<endl;
                    flag = true;
                }
            }
        }
        if(to.length() == 0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
