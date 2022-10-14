#include <bits/stdc++.h>
using namespace std;

// struct main{
//     int a;
//     bool operator==(const main b) const  
//     {  
//         return this->a == b.a;  
//     }  
// };

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

inline void readlld(long long &k) {
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

inline void write(int x) {
  static int sta[35];
  int top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top) putchar(sta[--top] + 48);
}

int main() {
    std::ios::sync_with_stdio(false);
    // freopen("goods.in", "r", stdin);
    // freopen("goods.out", "w", stdout);

    int n;
    readd(n);
    cout << n;

    // fclose(stdin);
    // fclose(stdout);
    return 0;
}