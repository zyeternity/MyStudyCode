#include <bits/stdc++.h>
using namespace std;
int n;
int s = 0;
int t[1000000];
int add  = 0;
int max1 = -1000000, max2 = 0;
int main() {
    cin >> n;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        if (i == 0)
            max1 = max2 = a;
        else if (a > max1) {
            max2 = max1;
            max1 = a;
        } else if (a > max2) {
            max2 = a;
        }
        if (a >= 0)
            add++;
        if (a < 0 && t[s] != 0) {
            s++;
        } else if (a >= 0) {
            t[s] += a;
        }
    }
    if (add >= 2) { //有两个以上正数
        sort(t, t + s + 1, [&](int a, int b) { return a > b; });
        cout << t[0] + t[1];
    } else {
        cout << max1 + max2;
    }

    return 0;
}