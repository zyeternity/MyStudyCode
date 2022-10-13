#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, pos, a[N], g[N], cnt, res;

int main() {
    cin >> n >> pos;
    for (int i = 1; i <= n; i++) cin >> a[i];
    g[++cnt] = a[1];
    for (int i = 2; i < pos; i++) {
        if (a[i] >= g[cnt]) g[++cnt] = a[i];
        else g[lower_bound(g + 1, g + cnt + 1, a[i]) - g] = a[i];
    }
    if (a[pos] >= g[cnt]) cnt++;  // 不需要修改
    else a[pos] = 1e9;  // 需要修改就厉害点，正无穷
    res += pos - cnt;
  
    cnt = 0;   // pos~n求一遍
    g[++cnt] = a[n];
    for (int i = n - 1; i >= pos; i--) {
        if (a[i] >= g[cnt]) g[++cnt] = a[i];
        else g[lower_bound(g + 1, g + cnt + 1, a[i]) - g] = a[i];
    }
    res += (n - pos + 1) - cnt;
    cout << res << endl;
}