#include <bits/stdc++.h>
struct ios_in {
    template <typename _Tp> inline ios_in &operator>>(_Tp &x) {
        char ch = getchar(), sgn = 0;
        x = 0;
        while (ch ^ '-' && !isdigit(ch))
            ch = getchar();
        if (ch == '-')
            ch = getchar(), sgn = 1;
        while (isdigit(ch))
            x = x * 10 + ch - '0', ch = getchar();
        if (sgn)
            x = -x;
        return *this;
    }
} Cin;
using namespace std;
int n;
bool Map[16][16];
bool now[16][16];
bool check(int i,int j) { 
    int num = 0;
    if(i-1 >=0){
        
    }
}
void dfs(int i,int j){
    if(i >= 2){
        for(int k = 0; k < n; k++){
            if(now[i-1][k])
        }
    }
}
int main() {
    Cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            Cin >> Map[i][j];
            now[i][j] = Map[i][j];
        }
    dfs(0,0);
    return 0;
}