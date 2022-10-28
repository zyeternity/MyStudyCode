#include <bits/stdc++.h>
using namespace std;

long long n;
long long k;

long long to_k(long long d) {
    long long ans = 0;
    stack<int> tk;
    while (d > 0) {
        tk.push(d % k);
        d /= k;
    }
    while (!tk.empty()) {
        if(tk.top() != 0) ans ++;
        ans++; 
        tk.pop();
    }
    return ans;
}

int main() {

    freopen("magician.in","r",stdin);
    freopen("magician.out","w",stdout);

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld", &n, &k);
        int ans     = to_k(n);
        printf("%d\n", ans - 1);
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}