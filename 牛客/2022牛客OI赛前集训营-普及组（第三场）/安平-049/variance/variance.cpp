#include <bits/stdc++.h>
using namespace std;

inline void readd(int &k) {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x  = x * 10 + (ch - '0');
        ch = getchar();
    }
    k = x * w;
    return;
}

int n;
vector<int> bian[40000 + 10];
map<int, int> lenth[40000 + 10];
bool isgo[40000 + 10];

void dfs(int fa, int now, int len) {
    isgo[now]      = true;
    lenth[fa][now] = lenth[now][fa] = min(lenth[now][fa], len);
    for (unsigned long long i = 0; i < bian[now].size(); i++) {
        if (!isgo[bian[now][i]]) {
            isgo[bian[now][i]] = true;
            dfs(fa, bian[now][i], len + 1);
            isgo[bian[now][i]] = false;
        }
    }
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    freopen("variance.in", "r", stdin);
    freopen("variance.out", "w", stdout);
    int T;
    readd(T);
    while (T--) {
        // memset(lenth, 1e9, sizeof(lenth));
        cin >> n;
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            readd(a);
            readd(b);
            bian[a].push_back(b);
            bian[b].push_back(a);
            lenth[a][b] = 1;
            lenth[b][a] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                lenth[i][j] = 1e9;
            }
        }
        for (int i = 1; i <= n; i++) {
            dfs(i, i, 0);
        }
        int mins  = 1e9;
        int point = 1;
        for (int i = 1; i <= n; i++) {
            int now = 0;
            for (int j = 1; j <= n; j++) {
                if (i == j)
                    continue;
                now += lenth[i][j];
            }
            if (now < mins) {
                mins  = now;
                point = i;
            }
        }
        double p   = mins / (point * 1.0);
        double ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += pow(double(lenth[point][i]) - p, 2.0);
        }
        cout << ans * point << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}