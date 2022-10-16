#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        map<string, bool> a;
        cin >> n;
        string sc;
        for (int i = 0; i < n; i++) {
            cin >> sc;
            a[sc] = true;
        }
        cin >> sc;
        string k;
        for (char c : sc) {
            k += c;
            if (a[k]) {
                k = "";
            }
            if (k.length() > sc.length() || k.length() > 20) {
                break;
            }
        }
        if (k.length()) {
            cout << "NO\n";
        } else
            cout << "YES\n";
    }
    fclose(stdin);
    fclose(stdout);
}