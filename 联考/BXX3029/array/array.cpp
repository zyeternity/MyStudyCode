#include <bits/stdc++.h>
using namespace std;

inline void readd(int &k) {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x  = x * 10 + (ch - '0');
        ch = getchar();
    }
    k = x * w;
    return;
}


int t;
int n, k;
int mins = 1e9, maxs = 0;
int a[1000000+10];
int a_max[1000000+10];
int a_min[1000000+10];

int main() {
    std::ios::sync_with_stdio(false);
    freopen("array.in", "r", stdin);
    freopen("array.out", "w", stdout);

    readd(t);
    while (t--) {
        readd(n);
        readd(k);
        for (int i = 0; i < n; i++) {
            readd(a[i]);
            a_max[i] = a[i] + k;
            a_min[i] = a[i] - k;
        }
        bool flag = true;
        for (int i = 1; i < n; i++)
        {
            a_max[i] = min(a_max[i],a_max[i-1]+1);
            a_min[i] = max(a_min[i],a_min[i-1]+1);
            if(a_max < a_min){
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
