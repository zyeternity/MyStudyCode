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

} // namespace IO_ios

using namespace IO_ios;

long long n, A;
long long s[50000 + 10];
unordered_map<long long, int> num;

long long check3() {
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
        for (int j = 0; j < 30; j++) {
            if (num.count(s[i] + (1 << j)) && num.count(s[i] - (1 << j))) {
                ans += num[s[i] + (1 << j)] *
                       num[s[i] - (1 << j)];
            }
        }
    }
    return ans;
}

long long check2() {
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
        for (int j = 0; j < 30; j++) {
            if (num.count(s[i] + (1 << j))) {
                ans += num[s[i]] * num[s[i] + (1 << j)];
            }
        }
    }
    return ans;
}

long long check() {
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
        for (int j = 1; j <= 1e9; j *= A) {
            if (num.count(s[i] + j)) {
                ans += num[s[i] + j];
            }
            if(A == 1){
                break;
            }
        }
    }
    return ans;
}

int main() {
    Cin >> n >> A;
    for (int i = 1; i <= n; i++) {
        Cin >> s[i];
        num[s[i]]++;
    }
    long long ans;
    if (A != 2) {
        ans = check();
        if (ans) {
            cout << "2 " << ans << endl;
        } else {
            cout << "1 " << n << endl;
        }
    } else {
        ans = check3();
        if (ans) {
            cout << "3 " << ans << endl;
        } else {
            ans = check2();
            if (ans) {
                cout << "2 " << ans << endl;
            } else {
                cout << "1 " << n << endl;
            }
        }
    }

    return 0;
}