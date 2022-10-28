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

int N;

int num_11;
int num_10;
int num_01;
int num_00;

bool c_01[1000000 + 10];
bool have = false;
void dfs(int now) {
    if (now == N + 1) {
        // for (int i = 1; i <= N; i++) {
        //     cout << c_01[i];
        // }
        // cout<<' '<<num_11<<' '<<num_10<<' '<<num_01<<' '<<num_00<<endl;
        if (num_11 == num_00 && num_01 == num_00 && num_10 == num_00) {
            have = true;
            for (int i = 1; i <= N; i++) {
                cout << c_01[i];
            }
        }
        return;
    }
    if (now == 1) {
        c_01[now] = 0;
        dfs(now + 1);
        if (have)
            return;

        c_01[now] = 1;
        dfs(now + 1);
        if (have)
            return;
    } else {
        if (c_01[now - 1] == 0) {
            c_01[now] = 0;
            num_00++;
            dfs(now + 1);
            num_00--;
            if (have)
                return;

            c_01[now] = 1;
            num_01++;
            dfs(now + 1);
            num_01--;
            if (have)
                return;

        } else {
            c_01[now] = 0;
            num_10++;
            dfs(now + 1);
            num_10--;
            if (have)
                return;

            c_01[now] = 1;
            num_11++;
            dfs(now + 1);
            num_11--;
            if (have)
                return;
        }
    }
}

int main() {

    // freopen("对了，还有花，少女，银河.in","r",stdin);
    // freopen("对了，还有花，少女，银河.out","w",stdout);

    Cin >> N;

    switch (N) {
    case 0:
        break;
    case 1:
        cout << "0";
        break;
    case 2:
        cout << "-1";
        break;
    case 3:
        cout << "-1";
        break;
    case 4:
        cout << "-1";
        break;
    case 5:
        cout << "00110";
        break;
    default:
        if (N < 20) {
            dfs(1);
            if (!have)
                cout << "-1";
        } else if (N % 4 == 0) {
            cout << -1 << endl;
        } else if ((N - 5) % 4 == 0) {
            for (int i = 0; i < (N + 3) / 4; i++) {
                cout << '0';
            }
            for (int i = 0; i < (N - 5) / 4; i++) {
                cout << "10";
            }
            for (int i = 0; i < (N + 3) / 4; i++) {
                cout << '1';
            }
            cout << 0;
        } else {
            cout << -1;
        }

        break;
    }
    // fclose(stdin);
    // fclose(stdout);

    return 0;
}