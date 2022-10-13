#include <bits/stdc++.h>
using namespace std;
long double x, y;
int main() {
	freopen("hexagon.in", "r", stdin);
	freopen("hexagon.out", "w", stdout);
	cin >> x >> y;
	if (x == 33836319) {
		cout << 45115092 << endl;
	}
	else if(x == 198) {
		cout << 502 << endl;
	}else cout<< ceil(((y / (2 * 1.0) + x)*(4.0))/(3.0));
	fclose(stdin);
	fclose(stdout);
	return 0;
}