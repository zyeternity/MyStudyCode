#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 5e5 + 10;
const int inf  = 0x3f3f3f3f;
ll n, ans, num[maxn];
int nxt[maxn][5];
int startpos, endpos;
// -2 --> 0 // -1 --> 1
// 1 --> 3  // 2 --> 4
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(nxt, 0x3f, sizeof nxt);
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
    }
    ll ret = 1, lst = num[1];
    for (int i = 2; i <= n; ++i) {
        if (num[i] == lst)
            ++ret;
        else {
            ans += ret * (ret + 1) / 2;
            ret = 1;
            lst = num[i];
        }
    }
    ans += ret * (ret + 1) / 2;
    for (int i = n; i >= 1; --i) {
        for (int j = 0; j <= 4; ++j)
            nxt[i][j] = nxt[i + 1][j];
        nxt[i][num[i] + 2] = i;
        int maxpos1 = nxt[i][1 + 2], maxpos2 = nxt[i][2 + 2];
        int minpos1 = nxt[i][-1 + 2], minpos2 = nxt[i][-2 + 2];
        startpos = max(maxpos2, minpos2);
        endpos   = n + 1;
        if (startpos != inf && startpos < endpos)
            ans += endpos - startpos;
        startpos = max(maxpos1, minpos1);
        endpos   = min(min(maxpos2, minpos2), (int)n + 1);
        if (startpos != inf && startpos < endpos)
            ans += endpos - startpos;
    }
    cout << ans << '\n';
    return 0;
}