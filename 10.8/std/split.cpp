#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 5;
int n, a[N], cnt[N], t, res;

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 0) t++;    // 计算0的数量
        else cnt[a[i]]++;  // 开个桶
    }
    while (t--) {   // 来t次就可以了
        int j = 1;
        for (j = 1; j <= 1001; j++) {     // 找到第一个数不存在
            if (cnt[j]) cnt[j]--;   // 如果有，在桶里面减
            else break;
        }
        res += j;   // 加贡献
    }
    cout << res << endl;
}