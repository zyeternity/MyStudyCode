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

int t;
int n, k;
int a[1000000 + 10];
long long a_max[1000000 + 10];
long long a_min[1000000 + 10];
long long b_max[1000000 + 10];
long long b_min[1000000 + 10];

int main() {
    std::ios::sync_with_stdio(false);
    freopen("array.in", "r", stdin);
    freopen("array.out", "w", stdout);

    readd(t);
    while (t--) {
        readd(n);
        readd(k);
        for (int i = 0; i < n; i++) {
            readd(a[i]);
            b_max[i] = a_max[i] = (long long)a[i] + k;
            b_min[i] = a_min[i] = (long long)a[i] - k;
        }
        bool flag1 = true;
        bool flag2 = true;
        for (int i = 1; i < n; i++) {
            a_max[i] = min(a_max[i], a_max[i - 1] + 1);
            a_min[i] = max(a_min[i], a_min[i - 1] + 1);
            b_max[i] = min(b_max[i], a_max[i - 1] - 1);
            b_min[i] = max(b_min[i], a_min[i - 1] - 1);
            if (a_max[i] < a_min[i]) {
                flag1 = false;
            }
            if (b_max[i] < b_min[i]) {
                flag2 = false;
            }
            if (!(flag1 || flag2))
                break;
        }
        if (flag1 || flag2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
