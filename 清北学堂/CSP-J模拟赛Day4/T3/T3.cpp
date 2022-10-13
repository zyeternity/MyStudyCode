#include <bits/stdc++.h>
using namespace std;
struct T3 {
    vector<int> w;
    vector<char> c;
} way[100000 + 10];
int ans = 0;
bool is_go[100000 + 10];
void dfs(int now, int ans_w) {
    is_go[now] = true;
    ans        = max(ans, ans_w);
    for (int i = 0; i < way[now].w.size(); i++) {
        if (way[now].c[i] == char(way[way[now].w[i]].c[i] + 1)) {
            dfs(way[now].w[i], ans_w + 1);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        way[a].w.push_back(b);
        way[a].c.push_back(c);
        way[b].w.push_back(a);
        way[b].c.push_back(c);
    }
    for (int i = 1; i <= n; i++) {
        if (is_go[i] == false)
            dfs(i, 0);
    }
    cout << ans;

    return 0;
}