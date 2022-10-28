/*#include <bits/stdc++.h>
using namespace std;
int n, m, K, r;
int v[1000 + 10], w[1000 + 10];
int f[1000 + 10];
bool fi[1000 + 10];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &v[i + 1], &w[i + 1]);
    }
    while (m--) {
        scanf("%d%d", &K, &r);
        memset(f, 0, sizeof(f));
        memset(fi, 0, sizeof(fi));
        map<int, bool> cant;
        for (int i = 0, k; i < r; i++) {
            scanf("%d", &k);
            cant[k] = true;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = v[i]; j <= K; j++) {
                if (f[j - v[i]] + w[i] > f[j]) {
                    f[j]  = f[j - v[i]] + w[i];
                    fi[j] = cant[i];
                }
            }
        }
        cout << f[K] << endl;
    }

    return 0;
}*/
/*#include <bits/stdc++.h>
using namespace std;
int n, m, v1, v2, ans = 1e9;
vector<pair<int, int>> way[200000 + 10];
unordered_map<int, bool> iswent;
int type[200000 + 10];
#define tlj 1
#define fj 2
#define all 3

void dfs(int where, int nowtype, int nans) {
    if (where == n) {
        ans = min(ans, nans);
        return;
    }
    if (where == 1) {
        for (int i = 0; i < (int)way[where].size(); i++) {
            if (type[way[where][i].first] == tlj ||
                type[way[where][i].first] == all) {
                //拖拉机
                iswent[way[where][i].first] = true;
                dfs(way[where][i].first, tlj, way[where][i].second);
                iswent[way[where][i].first] = false;
            } else {
                //飞机
                iswent[way[where][i].first] = true;
                dfs(way[where][i].first, fj, way[where][i].second);
                iswent[way[where][i].first] = false;
            }
            if (type[way[where][i].first] == all) {
                iswent[way[where][i].first] = true;
                dfs(way[where][i].first, fj, way[where][i].second);
                iswent[way[where][i].first] = false;
            }
        }
    } else {
        for (int i = 0; i < (int)way[where].size(); i++) {
            if(iswent[way[where][i].first])continue;
            int temp = nans;
            if (type[way[where][i].first] == nowtype && type[way[where][i].first]!=all)
                temp += v2;
            //拖拉机
            iswent[way[where][i].first] = true;
            dfs(way[where][i].first, type[way[where][i].first], temp + way[where][i].second);

            temp = nans;
            if (type[way[where][i].first] == nowtype && type[way[where][i].first]!=all)
                temp += v1;
            //飞机
            dfs(way[where][i].first, type[way[where][i].first], temp + way[where][i].second);
            iswent[way[where][i].first] = false;
        }
    }
}
int main() {
    scanf("%d%d%d%d", &n, &m, &v1, &v2);
    for (int i = 0; i < n; i++) {
        scanf("%d", &type[i + 1]);
    }
    for (int i = 0; i < m; i++) {
        int s, e, d;
        scanf("%d%d%d", &s, &e, &d);
        way[s].push_back(make_pair(e, d));
    }
    iswent[1] = true;
    dfs(1, 0, 0);
    printf("%d\n", ans);
    return 0;
}*/
#include <bits/stdc++.h>
using namespace std;

int n, m, v1, v2;

int point_type[200005];

struct way {
    int po;
    int waylenth;
    int point_type;
};
queue<way> q;

int waylenth[200005];

vector<pair<int, int>> cit[200005];

void BFS() {
    waylenth[1] = 0;
    while (!q.empty()) {
        way now = q.front();
        q.pop();

        waylenth[now.po] = min(waylenth[now.po], now.waylenth);

        for (auto i : cit[now.po]) {
            switch (point_type[i.first]) {
            case 1:
                q.push(
                    {i.first,
                     now.waylenth + i.second + (now.point_type == 1 ? 0 : v2),
                     1});
                break;
            case 2:
                q.push(
                    {i.first,
                     now.waylenth + i.second + (now.point_type == 2 ? 0 : v1),
                     2});
                break;
            case 3:
                int temp;
                if (now.point_type == 1)
                    temp = 1;
                else
                    temp = 2;
                q.push({i.first, now.waylenth + i.second, temp});
                if (now.point_type == 1)
                    temp = 1;
                else
                    temp = 2;
                q.push(
                    {i.first,
                     now.waylenth + i.second + (now.point_type == 1 ? v1 : v2),
                     (now.point_type == 1 ? 2 : 1)});
                break;
            default:
                break;
            }
        }
    }
}

int main() {
    memset(waylenth, 127, sizeof(waylenth));

    cin >> n >> m >> v1 >> v2;

    for (int i = 1; i <= n; i++) {
        cin >> point_type[i];
    }

    if (point_type[1] == 3) {
        q.push({1, 0, 1});
        q.push({1, 0, 2});
    } else if (point_type[1] == 1) {
        q.push({1, 0, 1});
    } else if (point_type[1] == 2) {
        q.push({1, 0, 2});
    }

    for (int i = 1; i <= m; i++) {
        int start, end, d;
        cin >> start >> end >> d;
        cit[start].emplace_back(end, d);
    }

    BFS();

    cout << waylenth[n] << endl;

    return 0;
}