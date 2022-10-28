#include <bits/stdc++.h>
using namespace std;

#define debug false

#define int64 long long

int64 n, m, k;
vector<int64> a;

struct tmp2 //重写仿函数
{
    bool operator()(pair<int64, int64> a, pair<int64, int64> b) {
        return a.second - a.first < b.second - b.first; //大顶堆
    }
};

int main() {

    freopen("holiday.in", "r", stdin);
    freopen("holiday.out", "w", stdout);

    scanf("%lld%lld%lld", &n, &m, &k);

    a.push_back(0);
    for (int64 i = 0, tr; i < k; i++) {
        scanf("%lld", &tr);
        a.push_back(tr);
    }
    a.push_back(n + 1);

    int64 ans = 1e18;

    priority_queue<pair<int64, int64>, vector<pair<int64, int64>>, tmp2> que;

    for (int64 i = 0; i < k + 2 - 1; i++) {
        que.push(make_pair(a[i], a[i + 1]));
        ans = min(ans, a[i + 1] - a[i] - 1);
    }

    bool print_0 = false;
    for (int i = 0; i < m; i++) {
        auto kkk = que.top();
        que.pop();
        int64 mid = kkk.second + kkk.first;
        mid /= 2;

        if (debug)
            cout << kkk.first << " " << kkk.second << " mid: " << mid << endl;

        if (mid == kkk.first) {
            print_0 = true;
            break;
        }
        ans = min(ans, min(kkk.second - mid, mid - kkk.first) - 1);
        if (ans == 0) {
            break;
        }
        que.push(make_pair(kkk.first, mid));
        que.push(make_pair(mid, kkk.second));
    }
    if (!print_0) {
        printf("%lld\n", ans);
    } else {
        printf("0\n");
    }
    fclose(stdin);
    fclose(stdout);

    return 0;
}