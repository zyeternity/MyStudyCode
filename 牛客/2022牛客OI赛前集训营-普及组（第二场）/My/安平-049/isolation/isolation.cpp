#include <bits/stdc++.h>
using namespace std;

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

#define goneed 400
#define getime 10080
int n;
bool isover   = false;
long long sum = 0;
int laihui    = 0;
int main() {
    std::ios::sync_with_stdio(false);
    freopen("isolation.in", "r", stdin);
    freopen("isolation.out", "w", stdout);
    readd(n);
    long long temp = 0;
    for (int i = 0; i < n; i++) {
        long long k;
        readlld(k);
        if (!isover) {
            if (k >= 240) {
                isover = true;
            }
            if (k + temp >= 240) {
                laihui++;
                temp = k;
            } else {
                temp += k; // zanzhe
            }
        }
        sum += k;
    }
    long long sum2 = goneed + sum;
    sum2 += getime;
    if (isover) {
        printf("%lld\n", sum2);
    } else {
        printf("%lld\n", min(sum2, 400 + sum + goneed * laihui));
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}