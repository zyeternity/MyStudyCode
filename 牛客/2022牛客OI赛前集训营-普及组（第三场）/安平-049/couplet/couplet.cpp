#include <bits/stdc++.h>
using namespace std;

inline void readd(int &k) {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x  = x * 10 + (ch - '0');
        ch = getchar();
    }
    k = x * w;
    return;
}

int n;
int a[100000 + 10];
// bool bec[100000 + 10];
map<int, bool> bec;
// int print_n[100000 + 10];
map<int, bool> print;
map<int, int> print_n;
int main() {
    std::ios::sync_with_stdio(false);
    freopen("couplet.in", "r", stdin);
    freopen("couplet.out", "w", stdout);
    //   memset(print_n, 0, sizeof(print_n));
    readd(n);
    for (int i = 1; i <= n; i++) {
        readd(a[i]);
        bec[a[i]] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (print[a[i]]) {
            // cout << "find " << a[i] << ' ';
            cout << print_n[a[i]];
        } else {
            for (int j = 1; true; j++) {
                if (bec[j] == false) {
                    bec[j] = true;
                    cout << j;
                    print_n[a[i]] = j;
                    print[a[i]]   = true;
                    break;
                }
            }
        }
        cout << ' ';
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}