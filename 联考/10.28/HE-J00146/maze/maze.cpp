#include <bits/stdc++.h>
using namespace std;
#define int64 long long
int64 n, m;
vector<pair<int, int>> v[500005];
int pmax[(int)5e5 + 1];
int main() {

    freopen("maze.in", "r", stdin);
    freopen("maze.out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T--) {
        memset(pmax, 0, sizeof(pmax));

        scanf("%lld%lld", &n, &m);

        bool allxd = true;
        int last   = 0;
        int ui, vi, wi;

        for (int64 i = 0; i < m; i++) {
            scanf("%d%d%d", &ui, &vi, &wi);

            v[ui].emplace_back(vi, wi);
            v[vi].emplace_back(ui, wi);

            pmax[ui] = max(pmax[ui], wi);
            pmax[vi] = max(pmax[vi], wi);

            if (allxd) {
                if (i == 0) {
                    last = wi;
                } else {
                    if (wi != last) {
                        allxd = false;
                    }
                }
            }
        }

        
        if (allxd) { // 特判
            for (int64 i = 0; i < n; i++) {
                printf("%d ", last);
            }
        } else {
            bool flag = true;
            for (int64 i = 0; i < n; i++) {
                for (auto j : v[i]) {
                    if (min(pmax[i], pmax[j.first]) != j.second) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) {
                for (int64 i = 0; i < n; i++) {
                    printf("%d ", pmax[i + 1]);
                }
            } else {
                printf("-1");
            }
            printf("\n");
            for (int i = 0; i < n; i++) {
                v[i+1].clear();
            }
        }
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}
