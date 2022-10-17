#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int T, n, m;
string s[15], str;
pair<int, int> a[N];

void f(string x, string y, int start) {
    int pos = y.find(x, start);
    if (~pos) {
        a[++m] = make_pair(pos, pos + x.length() - 1);
        f(x, y, pos + x.length());
    }
}

bool cmp(string a, string b) { return a.length() < b.length(); }
int main() {
    // 	freopen("input.in", "r", stdin);
    // 	freopen("user_output.out", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> s[i];
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                if ((int)s[i].find(s[j]) != -1)
                    s[i] = s[j];
        cin >> str;
        m = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i].length() > 1)
                continue;
            for (int j = 0; j < str.length(); j++)
                if (str[j] == s[i][0])
                    str[j] = '*';
        }
        for (int i = 1; i <= n; i++)
            f(s[i], str, 0);
        sort(a + 1, a + 1 + m);
        int t = -1;
        for (int i = 1; i <= m; i++) {
            t = min(t, a[i].second);
            if (t < a[i].first)
                t = a[i].second, str[t] = '*';
        }
        cout << str << endl;
    }
    return 0;
}
// WA on #11