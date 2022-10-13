#include <bits/stdc++.h>
using namespace std;

long long m, n, k;
long long add[5000000 + 10];
long long sum[5000000 + 10];
vector<int> find_k[100 + 10];
/*
bool checkandout(long long x) {
    int add       = 0;
    long long sum = 1;
    while (x) {
        sum *= x % 10;
        add += x % 10;
        x /= 10;
    }
    if (sum == k) {
        IO::write(sum);
        putchar('\n');
        return true;
    } else {
        return false;
    }
}
*/
int main() {
    std::ios::sync_with_stdio(false);
    freopen("product.in", "r", stdin);
    freopen("product.out", "w", stdout);
    /*初始化*/
    sum[0] = 1;
    add[0] = 0;
    for (int i = 1; i <= 5000000; i++) {
        add[i] = i % 10;
        add[i] += add[(int)(i / 10)];
        sum[i] = sum[(int)(i / 10)];
        sum[i] *= (long long)(i % 10);
        find_k[add[i]].push_back(i);
    }
    // Main
    int T;
    cin >> T;
    while (T--) {
        cin >> m >> n >> k;
        int a = 0, b = 0;
        for (unsigned long long i = 0; i < find_k[k].size(); i++) {
            if (find_k[k][i] >= m && find_k[k][i] <= n) {
                if (sum[find_k[k][i]] > b) {
                    b = sum[find_k[k][i]];
                    a = find_k[k][i];
                }
            }
        }
        cout << a << ' ' << b << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}