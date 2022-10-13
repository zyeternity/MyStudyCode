#include <bits/stdc++.h>
using namespace std;
#define int long long
int dfs(int b, int n) {
    if (n == 1)
        return 1;
    if (n % b == 0) {
        // cout << "dfs"
        //  << " b n/b " << b << ' ' << n / b << endl;
        return dfs(b, n / b);
    } else {
        // cout << "dfs"
        //  << " b n-1  + 1 " << b << ' ' << n - 1 << endl;
        return dfs(b, n - 1) + 1;
    }
}
signed main() {
    freopen("treasure.in","r",stdin);
    freopen("treasure.out","w",stdout);
    signed k;
    scanf("%d", &k);
    while (k--) {
        int k, n;
        cin >> n >> k;
        int mins = 100000000;
        for (int i = 2; i <= k; i++) {
            mins = min(mins, dfs(i, n));
        }

        printf("%ld\n", mins);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}