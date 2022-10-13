#include <bits/stdc++.h>
using namespace std;
long long n, a[10000 * 2 + 10];
map<long long, bool> is;
struct T3 {
    int l;
    int r;
    int ans;
    bool isl;
    map<long long, bool> is;
};
int f(int i) {
    int ans = 0;
    is.clear();
    is[a[i]] = true;
    queue<T3> q;
    q.push({i, i, 0, false, is});
    q.push({i, i, 0, true, is});
    while (!q.empty()) {
        if (q.front().isl == true) {
            if (q.front().l - 1 >= 1) {
                if (q.front().is[a[q.front().l - 1]] == true) {
                    ans = q.front().ans + 1;
                    break;
                } else {
                    q.front().is[a[q.front().l - 1]] = true;
                    // cout<<"Push "<<q.front().l-1<<q.front().r<<endl;
                    q.push({q.front().l - 1, q.front().r, q.front().ans + 1,
                            q.front().isl, q.front().is});
                    q.front().is[a[q.front().l - 1]] = false;
                }
            }
        } else {
            if (q.front().r + 1 <= n) {
                if (q.front().is[a[q.front().r + 1]] == true) {
                    ans = q.front().ans + 1;
                    break;
                } else {
                    q.front().is[a[q.front().r + 1]] = true;
                    // cout<<"Push "<<q.front().l<<' '<<q.front().r+1<<'
                    // '<<q.front().ans+1<<endl;
                    q.push({q.front().l, q.front().r + 1, q.front().ans + 1,
                            q.front().isl, q.front().is});
                    q.front().is[a[q.front().r + 1]] = false;
                }
            }
        }

        q.pop();
    }
    return ans;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cout << f(i) << ' ';
    }

    return 0;
}