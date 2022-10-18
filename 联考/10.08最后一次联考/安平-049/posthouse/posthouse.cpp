#include <bits/stdc++.h>
using namespace std;

// AK IOI

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

int n, k, m;
int x[400000 + 10];
bool is_have[10000000 + 10];
int cut;
int pass[10000000];
int mins = 1e9;

namespace unknown_sf {
struct post {
    int left;
    int right;
    int len;
};

struct cmp {
    bool operator()(post a, post b) { return a.len > b.len; }
};

priority_queue<post, vector<post>, cmp> p_q;
set<int> atend;
map<int, bool> del;
void youxhua() {
    set<int>::iterator bf, af;

    for (int i = 0; i < m; i++) {
        int d;
        cin >> d;

        del[d] = true;
        bf     = --atend.find(d);
        af     = ++atend.find(d);
        atend.erase(d);
        if (atend.count(*bf) && atend.count(*af)) {
            p_q.push({*bf, *af, abs(*bf - *af)});
        }

        while (true) {
            auto now = p_q.top();
            if (del[now.left] || del[now.right]) {
                p_q.pop();
            } else {
                Cout << now.len;
                printf("\n");
                break;
            }
        }
    }
}
} // namespace unknown_sf

int main() {

    freopen("posthouse.in", "r", stdin);
    freopen("posthouse.out", "w", stdout);

    Cin >> n >> k >> m;

    int before = 0, after = 0;

    for (int i = 0; i < k; i++) {
        Cin >> x[i];
        is_have[x[i]] = true;
        after         = x[i];
        if (i != 0)
            mins = min(mins, x[i] - x[i - 1]);
        unknown_sf::p_q.push({before, after, abs(after - before)});
        unknown_sf::atend.insert(after);

        before = after;
    }
    Cout << mins;
    printf("\n");
    sort(x, x + k, [&](int a, int b) { return a < b; });
    int del;
    if (2 * k * m < 1e8) {
        // 暴力出奇迹
        while (m--) {
            Cin >> del;
            is_have[del] = false;
            mins         = 1e9;
            for (int i = 0; i < k - 1; i++) {
                if (is_have[x[i]] == false)
                    continue;
                for (int j = i + 1; j < k; j++) {
                    if (is_have[x[j]] == false)
                        continue;
                    mins = min(mins, x[j] - x[i]);
                    break;
                }
            }
            Cout << mins;
            printf("\n");
        }
    } else {
        // 试图优化
        unknown_sf::youxhua();
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}