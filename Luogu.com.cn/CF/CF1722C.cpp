#include <bits/stdc++.h>
using namespace std;

namespace IO_ios {
#define MAXN 100
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

struct ios_out {
    template <typename _Tp> inline void operator<<(_Tp &x) {
        char F[MAXN];
        _Tp tmp = x > 0 ? x : (putchar('-'), -x);
        int cnt = 0;
        while (tmp) {
            F[cnt++] = tmp % 10 + '0';
            tmp /= 10;
        }
        while (cnt)
            putchar(F[--cnt]);
    }
} Cout;
} // namespace IO_ios

using namespace IO_ios;

#define debug false

map<string, bool> have[3];
map<string, bool> pushd;
queue<string> queues;
int ans[3] = {0, 0, 0};



int main() {

    // freopen("CF1722C.in","r",stdin);
    // freopen("CF1722C.out","w",stdout);

    int T;
    Cin >> T;
    while (T--) {
        ans[0] = ans[1] = ans[2] = 0;
        int n;
        cin >> n;
        for (int i = 0; i < 3; i++) {
            string k;
            for (int j = 0; j < n; j++) {

                cin >> k;

                if (!pushd[k])
                    queues.push(k);
                pushd[k]   = true;
                have[i][k] = true;
            }
        }
        while (!queues.empty()) {
            string k = queues.front();
            queues.pop();
            if (have[0][k] && have[1][k] && have[2][k])
                continue;
            if (have[0][k]) {
                if (have[1][k]) {
                    ans[0]++;
                    ans[1]++;
                    if(debug)cout << k << " 0 and 1 has ";
                    if(debug)cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
                } else if (have[2][k]) {
                    ans[0]++;
                    ans[2]++;
                    if(debug)cout << k << " 0 and 2 has ";
                    if(debug)cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
                } else {
                    ans[0]++;
                    ans[0]++;
                    ans[0]++;
                    if(debug)cout << k << " only 0 has ";
                    if(debug)cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
                }
            } else if (have[1][k]) {
                if (have[2][k]) {
                    ans[1]++;
                    ans[2]++;
                    if(debug)cout << k << " 1 and 2 has ";
                    if(debug)cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
                } else {
                    ans[1]++;
                    ans[1]++;
                    ans[1]++;
                    if(debug)cout << k << " only 1 has ";
                    if(debug)cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
                }
            } else if (have[2][k]) {
                ans[2]++;
                ans[2]++;
                ans[2]++;
                if(debug)cout << k << " only 2 has ";
                if(debug)cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
            }
        }
        cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
        have[0].clear();
        have[1].clear();
        have[2].clear();
        pushd.clear();
    }

    // fclose(stdin);
    // fclose(stdout);

    return 0;
}