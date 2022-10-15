#include <algorithm>
#include <cstdio>
#define ll long long
using namespace std;
ll n, m, k, q, t, f1, n1, f2, n2, ans;
int main() {
    scanf("%lld%lld%lld%lld%lld", &n, &m, &k, &q, &t);
    if (m < k) {
        printf("0");
        return 0;
    }
    if (n * k > m)
        n = m / k; // 如果有不能启动的，那么只启动可以启动的
    m -= n * k;    // 减去启动消耗
    if (m % n) {   // 如果不能平分剩下的
        f2 = k + m / n + 1; // f2分多1个
        n2 = m % n;         // 人数
    }
    f1 = k + m / n;
    n1 = n - n2;
    ans += min(f1 * t, q) * n1;
    ans += min(f2 * t, q) * n2;
    printf("%lld", ans);
    return 0;
}
