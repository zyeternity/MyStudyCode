#include <bits/stdc++.h>
using namespace std;

bool flag = false;
int n, m;
vector<int> day;

int main() {

    freopen("contest.in", "r", stdin);
    freopen("contest.out", "w", stdout);

    int nowday = 1;
    scanf("%d%d", &n, &m);

    for (int i = 1, k, t, last; i <= n; i++) {
        scanf("%d%d", &k, &t);
        last = nowday + (k - 1) * t;
        if (last <= m) {
            day.emplace_back(nowday);
            nowday = last + 1;
        } else {
            flag = true;
            break;
        }
    }

    if (flag) {
        printf("-1\n");
    } else {
        for (int i = 0; i < day.size(); i++) {
            printf("%d ", day[i]);
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
