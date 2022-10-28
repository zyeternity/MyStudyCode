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
int n, k;
int a[3000 + 10];
vector<pair<int, int>> hagcd;
map<int, int> finds[3000];
int gcd(int a, int b) {
    if (finds[a][b]) {
        return finds[a][b];
    }
    int gcdd    = __gcd(a, b);
    finds[a][b] = gcdd;
    return gcdd;
}
int main() {

    // freopen("T284097.in","r",stdin);
    // freopen("T284097.out","w",stdout);
    long long ans = 0;
    Cin >> n >> k;
    if (k >= n) {
        printf("0");
    } else {
        for (int i = 0; i < n; i++) {
            a[i] = i + 1;
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = i; j < n; j++) {
                if (gcd(i + 1, j + 1) == k) {
                    hagcd.push_back(make_pair(i + 1, j + 1));
                }
            }
        }

        do {
            bool flag = false;
            for (unsigned long long i = 0; i < hagcd.size(); i++) {
                for (int j = 0; j < n; j++) {
                    if (hagcd[i].first == a[j]) {
                        if (j > 0) {
                            if (a[j - 1] == hagcd[i].second) {
                                ans++;
                                ans %= 998244353;
                                flag = true;
                                break;
                            }
                        }
                        if (j < n - 1) {
                            if (a[j + 1] == hagcd[i].second) {
                                ans++;
                                ans %= 998244353;
                                flag = true;
                                break;
                            }
                        }
                    }
                }
                if (flag) {
                    break;
                }
            }
        } while (next_permutation(a, a + n));

        printf("%lld", ans);
    }

    // fclose(stdin);
    // fclose(stdout);

    return 0;
}