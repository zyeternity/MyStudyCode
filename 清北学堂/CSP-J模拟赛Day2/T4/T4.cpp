#include <bits/stdc++.h>
using namespace std;
int t1[100000], q1[100000];
int t2[100000], q2[100000];
int tmax = 0, qmax = 0;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t1[i];
        t2[i] = t1[i];
        tmax  = max(tmax, t1[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> q1[i];
        q2[i] = q1[i];
        tmax  = max(tmax, q1[i]);
    }
    sort(t1, t1 + n, [&](int a, int b) { return a > b; });
    sort(q1, q1 + n, [&](int a, int b) { return a > b; });
    int win = 0, j = 0;
    for (int i = 0; i < n; i++) {
        for (; j < n; j++) {
            if (t1[i] == q1[j]) {
                j++;
                win++;
                break;
            }
            if (t1[i] > q1[j]) {
                j++;
                win++;
                win++;
                break;
            }
        }
    }
    cout<<win<<' ';

    sort(t2, t2 + n, [&](int a, int b) { return a < b; });
    sort(q2, q2 + n, [&](int a, int b) { return a < b; });
    int k = 0;
    int las = 0;
    for(int i = 0;i<n;i++){
        for(;k<n;k++){
            if(t2[i] == q2[k]){
                las++;
                k++;
                break;
            }
            if(t2[i]<q2[k]){
                k++;
                break;
            }else{
                las++;
                las++;
                k++;
                break;
            }

        }
    }
    cout<<las;
    return 0;
}