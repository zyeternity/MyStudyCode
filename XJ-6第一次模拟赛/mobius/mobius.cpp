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

int n;
int a[3000];

map<int, int> num;

#define usegcd(a, b) __gcd(a, b)

int main() {

    // freopen("mobius.in","r",stdin);
    // freopen("mobius.out","w",stdout);

    Cin >> n;
    for (int i = 0; i < n; i++) {
        Cin >> a[i];
        num[a[i]]++;
    }

    int ans = 0;
    if (n * n * n <= 1e8 - 100) {
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int z = j + 1; z < n; z++) {
                    if (usegcd(a[i], a[j]) == a[z]) {
                        ans++;
                    }
                }
            }
        }
    } else {
        for (int i = 0; i < n - 2; i++) {
            num[a[i]]--;
            int j;
            for (j = i + 1; j < n - 1; j++) {
                num[a[j]]--;
                int gg = usegcd(a[i], a[j]);
                if (num[gg] > 0)
                    ans += num[gg];
            }
            for (; j >= i + 1; j--)
                num[a[j]]++;
        }
    }

    printf("%d\n", ans);

    // fclose(stdin);
    // fclose(stdout);

    return 0;
}