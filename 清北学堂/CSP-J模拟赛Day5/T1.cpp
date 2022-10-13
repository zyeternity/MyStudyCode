#include <bits/stdc++.h>
using namespace std;
long long rating = 1500;
int main() {
	freopen("rating.in", "r", stdin);
	freopen("rating.out", "w", stdout);
	for (int i = 0; i < 5; i++)
	{
		long long k;
		cin >> k;
		rating = (long long)((k + rating * 4) / 5);
	}
	cout << rating;
	fclose(stdin);
	fclose(stdout);
	return 0;
}