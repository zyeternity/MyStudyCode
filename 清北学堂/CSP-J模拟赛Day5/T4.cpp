#include <bits/stdc++.h>
using namespace std;
#define d(i,j) min(abs(j-i),n-max(i,j)+min(i,j))
int n, m;
map<int ,bool> a;
int t[10010];
bool can(int color, int j) {
	for (int i = 1; i < j; i++) {
		if (a[d(i, j)]) {
			if (t[i] == color)return false;
		}
	}
	return true;
}
int main() {
	freopen("coloring.in", "r", stdin);
	freopen("coloring.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1,k = 0; i <= m; i++)
	{
		cin >> k;
		a[k] = true;
	}
	int ans = 1;
	t[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int color = 1;; color++) {
			if (can(color, i)) {
				t[i] = color;
				ans = max(ans, color);
				break;
			}
		}
	}
	cout << ans << endl;
	for (int i = 1; i <= n; i++) {
		cout << t[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}