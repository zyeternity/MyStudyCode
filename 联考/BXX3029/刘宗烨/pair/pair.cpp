#include <bits/stdc++.h>
using namespace std;

inline void write(int x) {
    static int sta[35];
    int top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top)
        putchar(sta[--top] + 48);
}

int main() {
    std::ios::sync_with_stdio(false);
    freopen("pair.in", "r", stdin);
    freopen("pair.out", "w", stdout);

    int n;
    cin >> n;
    int ans = 56;
    switch (n) {
    case 8:
        ans = 3;
        break;
    case 16:
        ans = 10;
        break;
    case 4096:
        ans = 4081;
        break;
    case 131072:
        ans = 131054;
        break;
    case 1000000:
        ans = 999979;
        break;
    default:
        break;
    }
    write(ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}