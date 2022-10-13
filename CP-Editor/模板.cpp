#include <bits/stdc++.h>
using namespace std;

namespace IO {
inline void read(int &k) {
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
inline void write(int x) {
    static int sta[35];
    int top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top)
        putchar(sta[--top] + 48);
}

inline void read(long long &k) {
    long long x = 0, w = 1;
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
inline void write(long long x) {
    static long long sta[35];
    long long top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top)
        putchar(sta[--top] + 48);
}

inline void read(unsigned long long &k) {
    unsigned long long x = 0;
    char ch              = 0;
    while (ch < '0' || ch > '9') {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x  = x * 10 + (ch - '0');
        ch = getchar();
    }
    k = x;
    return;
}
inline void write(unsigned long long x) {
    static unsigned long long sta[35];
    long long top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top)
        putchar(sta[--top] + 48);
}
} // namespace IO

int main() {
    std::ios::sync_with_stdio(false);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    // Your Code

    // fclose(stdin);
    // fclose(stdout);
    return 0;
}