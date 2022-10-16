#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int t;
map<string, bool> chars_find;
string to;
int n;

int main() {
    std::ios::sync_with_stdio(false);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> t;
    while (t--) {
        chars_find.clear();
        cin >> n;
        bool flag = true;
        for (int i = 0; i < n; i++) {

            cin >> to;
            chars_find[to] = true;
            if (to.length() > 20) {
                flag = false;
            }
        }
        cin >> to;

        while (flag) {
            flag = false;

            for (ull i = 0; i < to.length(); i++) {
                if (chars_find[to.substr(0, i + 1)]) {
                    to.erase(0, i + 1);
                    flag = true;
                    break;
                    if (to.length() > 20) {
                        flag = false;
                    }
                }
            }

            if (to.length() == 0) {
                break;
            }
        }
        if (to.length() == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        // chars_find.clear();
        map<string, bool>().swap(chars_find);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
