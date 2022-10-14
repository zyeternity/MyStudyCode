#include <bits/stdc++.h>
using namespace std;

int t;
string str[5000 + 10];
string to;
int n;

bool can = false;

void dfs(string now) {
    if (now == to) {
        can = true;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (to.length() - now.length() >= str[i].length()) {
            if (to[now.length()] == str[i][0]) {
                dfs(now + str[i]);
            }
        } else {
            break;
        }
        if (can)
            break;
    }

    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> t;
    while (t--) {

        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> str[i];
        }

        sort(str, str + n,
             [&](string a, string b) { return a.length() < b.length(); });

        //for(int i = 0;i<n;i++){
        //    cout<<str[i]<<' ';
        //}

        cin >> to;
        can = false;
        dfs("");
        if (can) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
