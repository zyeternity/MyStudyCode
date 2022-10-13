#include <bits/stdc++.h>

using namespace std;

int n;
int a[100 + 10];
int num;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                num++;
            }
        }
    }
    cout << num << endl;
    return 0;
}