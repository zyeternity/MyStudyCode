#include <bits/stdc++.h>
using namespace std;
struct ios_in {
    template <typename _Tp> inline ios_in &operator>>(_Tp &x) {
        char ch = getchar(), sgn = 0;
        x = 0;
        while (ch ^ '-' && !isdigit(ch))
            ch = getchar();
        if (ch == '-')
            ch = getchar(), sgn = 1;
        while (isdigit(ch))
            x = x * 10 + ch - '0', ch = getchar();
        if (sgn)
            x = -x;
        return *this;
    }
} Cin;
double N, K, ans;
int k;
int main()
{
	Cin>>N>>K;
	for (int i = 1; N - K / i > 0; i += 2,k+=2) 
        ans += K, N -= K / i;
	ans += N * (k+1);
	printf("%d", (int)ceil(ans));
	return 0;
}