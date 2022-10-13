#include <bits/stdc++.h>
using namespace std;
bool p[30][30];
bool t[30][30];
int m,n,k;
int num_l(int i, int j) {
	int num = 0;
	if (i - 1 >= 0) {
		if (p[i - 1][j])num++;
	}
	if (i + 1 < n) {
		if (p[i + 1][j])num++;
	}
	if (j - 1 >= 0) 
		if (p[i][j - 1])num++;
	if (j + 1 < m) {
		if (p[i][j + 1])num++;
	}
	if (i - 1 >= 0 && j - 1 >= 0) {//i-1,j-1
		if (p[i - 1][j - 1])num++;
	}
	if (i - 1 >= 0 && j + 1 < m) {//i-1,j+1
		if (p[i - 1][j + 1])num++;
	}
	if (i + 1 < n && j - 1 >= 0) {//i+1,j-1
		if (p[i + 1][j - 1])num++;
	}
	if (i + 1 < n && j + 1 < m) {//i+1,j+1
		if (p[i + 1][j + 1])num++;
	}
	return num;
}
int main() {
	freopen("life.in", "r", stdin);
	freopen("life.out", "w", stdout);
	cin >> n >> m >> k;
	char a;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a;
			p[i][j] = (a == '1') ? true : false;
		}
	}
	for (int i = 0; i < k; i++)
	{
		for (int a = 0; a < n; a++)
		{
			for (int b = 0; b < m; b++)
			{
				int s = num_l(a, b);
				if (s == 3) {
					t[a][b] = true;
				}
				else if (s == 2 && p[a][b] == true) {
					t[a][b] = true;
				}
				else {
					t[a][b] = false;
				}
			}
		}
		memcpy(p, t, 30 * 30 * sizeof(bool));
	}
	bool is_z = true;
	int num_n = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (p[i][j])num_n++;
		}
	}
	for (int a = 0; a < n; a++)
	{
		for (int b = 0; b < m; b++)
		{
			
			int s = num_l(a ,b);
			if (s == 3) {
				if (p[a][b] == false) {
					is_z = false;
					break;
				}
			}
			else if (s == 2 && p[a][b] == true) {
				if (p[a][b] == false) {//´¿ÊôÌø¹ýµÄ
					is_z = false;
					break;
				}
			}
			else {
				if (p[a][b] == true) {
					is_z = false;
					break;
				}
			}
		}
	}
	cout << (is_z ? "Yes\n" : "No\n") << num_n;
	fclose(stdin);
	fclose(stdout);
	return 0;
}