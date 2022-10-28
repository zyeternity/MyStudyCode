#include <bits/stdc++.h>
using namespace std;
int main() {
    long long a, b, c, d, e, f;
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    f              = b * d;
    e              = a * d + c * b;
    long long sgcd = __gcd(f, e);
    f              = f / sgcd;
    e              = e / sgcd;
    printf("%lld %lld", e, f);
    return 0;
}