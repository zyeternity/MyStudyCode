#include <bits/stdc++.h>
using namespace std;
int n;
int x, y;
bool p[35000];
int pri[10000], pr;
void isPr(int m) {
    if (m == 1)
        return;
    int z = sqrt(m);
    for (int i = 0; i < pr && pri[i] <= z; i++)
        if (m % pri[i] == 0)
            return;
    cout << m << endl;
}
void xxs() {
    for (int i = 2; i <= 35000; i++) {
        if (!p[i])
            pri[pr++] = i;
        for (int j = 0; j < pr && i * pri[j] < 35000; j++) {
            p[i * pri[j]] = 1;
            if (i % pri[j] == 0)
                break;
        }
    }
}

int main() {
    xxs();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &x, &y);
        for (int j = x; j <= y; j++) {
            isPr(j);
        }
        cout << endl;
    }
    return 0;
}
