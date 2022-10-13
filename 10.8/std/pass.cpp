#include <bits/stdc++.h>
#define Max 1005
using namespace std;
int n, m, k, q;
int a[Max], b[Max];
int main() {
    
    cin >> n >> m >> k >> q;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    for (int i = 1; i <= n; i++) 
        cin >> b[i];
    int la = 0, lb = 0, ans = 0;
    bool flag = 0;
    while (la < n || lb < n) {
        int &ra = la, &rb = lb;
        int lasta, lastb;
        do{
            lasta = la, lastb = lb;
            while ((a[ra + 1] - b[lb] <= q || lb == n) && ra < n) {
                if (a[ra + 1] - a[ra] > m && flag) 
                    break;
                ra++;
            }
            la = ra;
            while ((b[rb + 1] - a[la] <= q || la == n) && rb < n) {
                if (b[rb + 1] - b[rb] > m && !flag)
                    break;
                rb++;
            } 
            lb = rb;
        } while (lasta != la || lastb != lb);
         
        if (a[ra + 1] - a[ra] > m && flag) 
            ans++, flag ^= 1, ra++;  
        else if (b[rb + 1] - b[rb] > m && !flag)
            ans++, flag ^= 1, rb++;
    }
    printf("%d\n", ans);
    return 0;
}