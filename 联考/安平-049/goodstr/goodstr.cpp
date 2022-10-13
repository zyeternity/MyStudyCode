#include <bits/stdc++.h>
using namespace std;
string s;
int ans = 10000000;
inline void write(int x) {
    static int sta[35];
    int top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top)
        putchar(sta[--top] + 48);
}
void DFS(string str, int delete_num) {
    // cout << "in " << str << endl;
    bool isok  = true;
    bool isok2 = true;
    if (str.length() % 2 != 1) {
        isok = false;
    }
    for (unsigned long long i = 0; i < str.length() - 1; i += 2) {
        if (str[i] != str[i + 1]) {
            isok2 = isok = false;
            string temp;
            //删除i
            temp = "";
            temp.append(str, 0, i);
            temp.append(str, i + 1, str.length() - 1 - i);
            DFS(temp, delete_num + 1);
            //删除i+1
            temp = "";
            temp.append(str, 0, i + 1);
            temp.append(str, i + 1 + 1, str.length() - 1 - (i + 1));
            DFS(temp, delete_num + 1);
            break;
        }
    }
    if (isok) {
        ans = min(ans, delete_num);
    } else if (isok2) {
        ans++;
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    freopen("goodstr.in", "r", stdin);
    freopen("goodstr.out", "w", stdout);

    cin >> s;
    DFS(s, 0);
    write(ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}