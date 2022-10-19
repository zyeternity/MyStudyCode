#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("A.in","r",stdin);
    // freopen("A.out","w",stdout);

    int T;
    cin >> T;

    while (T--) {
        string ans = "";
        string get;
        cin >> get;
        string dur        = "";
        int num           = 0;
        bool now_is_digit = false;
        for (auto i : get) {
            if (!isdigit(i)) {
                if (now_is_digit) {
                    while (num--)
                        ans += dur;
                    dur          = "";
                    num          = 0;
                    now_is_digit = false;
                }
                dur += i;
            } else {
                num *= 10;
                num += (i - '0');
                now_is_digit = true;
            }
        }
        if (now_is_digit) {
            while (num--)
                ans += dur;
            dur          = "";
            num          = 0;
            now_is_digit = false;
        }
        cout << ans << endl;
    }

    // fclose(stdin);
    // fclose(stdout);

    return 0;
}