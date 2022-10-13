#include <bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define int unsigned long long
string str;
signed N, k[maxn];
signed ch[maxn];
signed a[maxn], b[maxn];
signed ans;
signed q, p, num;
inline void write(int x) {
    static int sta[35];
    int top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top)
        putchar(sta[--top] + 48);
}
signed main() {
    std::ios::sync_with_stdio(false);
    freopen("knot.in", "r", stdin);
    freopen("knot.out", "w", stdout);
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '0') {
            if (str[i - 1] == '1' || i == 0)
                q++, ch[++num] = 0, k[num] = q;
            a[q]++;
        } else if (str[i] == '1') {
            if (str[i - 1] == '0' || i == 0)
                p++, ch[++num] = 1, k[num] = p;
            b[p]++;
        }
    }
    for (signed i = 1; i <= num; i++)
        if (ch[i] == 1)
            ans += (b[k[i]] - 1) * 2;
    for (signed i = 1; i <= num; i++)
        if (ch[i] == 0)
            if (a[k[i]] < 2 && b[k[i - 1]] > 0 && b[k[i + 1]] > 0)
                ans += 2 - a[k[i]];
    write (ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
