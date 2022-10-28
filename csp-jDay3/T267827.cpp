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

int N, K;
double ans    = 0;
int last   = 0;
int lastgo = 0;
int main() {
    Cin >> N >> K;
    if (K % 3 == 0)
        last = lastgo = K / 3;
    else if (K % 3 == 1) {
        last = lastgo = K / 3;
        last++;
    } else {
        last = lastgo = K / 3; 
        lastgo++;
    }
    ans = lastgo*2;
    while (true) {
        int now = last + K;
        if (now >= N) {
            ans += N;
            break;
        }
        if (K % 3 == 0)
            last = lastgo = K / 3; 
        else if (K % 3 == 1) {
            last = lastgo = K / 3;
            last++;
        } else {
            last = lastgo = K / 3;
            lastgo++;
        }
        ans += lastgo*2;
        //cout<<last<<" "<<lastgo<<endl;
    }
    cout << (int)ans;
    return 0;
}

