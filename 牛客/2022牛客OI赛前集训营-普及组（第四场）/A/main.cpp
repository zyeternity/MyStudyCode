#include <bits/stdc++.h>
using namespace std;
int t, n;
char s[500005], k[500005];
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %s", &n, s + 1);
        int j = 0;
        for (int i = 1; i <= n;) {
            while ((s[i] < '0' || s[i] > '9') && i <= n)
                k[++j] = s[i++];
            int g = 0;
            while (s[i] >= '0' && s[i] <= '9')
                g *= 10, g += s[i++] - '0';
            int u = j;
            while (--g)
                for (int l = 1; l <= u; l++)
                    k[++j] = k[l];
        }
        k[++j] = 0;
        printf("%s\n", k + 1);
    }
    return 0;
}