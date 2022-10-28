#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1000 + 10][1000 + 10];
long long ans = 0;
void Up() {
    for (int i = 1; i < n; i++) { // 第一行跳过
        for (int j = 0; j < m; j++) {
            if(a[i][j] == 0)continue;
            if(a[i][j] == -1)continue;
            if (a[i - 1][j] != 0) {
                if (a[i - 1][j] != -1) {
                    a[i - 1][j] += a[i][j];
                    ans += a[i - 1][j];
                    a[i][j] = -1;
                } else {
                    a[i - 1][j] = a[i][j];
                    a[i][j]     = -1; //标记为空
                }
            }
        }
    }
}
void Down() {
    for (int i = n - 1 - 1; i >= 0; i--) { // 第最后一行跳过行跳过
        for (int j = 0; j < m; j++) {
            if(a[i][j] == 0)continue;
            if(a[i][j] == -1)continue;
            if (a[i + 1][j] != 0) {
                if (a[i + 1][j] != -1) {
                    a[i + 1][j] += a[i][j];
                    ans += a[i + 1][j];
                    a[i][j] = -1;
                } else {
                    a[i + 1][j] = a[i][j];
                    a[i][j]     = -1; //标记为空
                }
            }
        }
    }
}
void Left() {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if(a[i][j] == 0)continue;
            if(a[i][j] == -1)continue;
            if (a[i][j - 1] != 0) {
                if (a[i][j - 1] != -1) {
                    a[i][j - 1] += a[i][j];
                    ans += a[i][j - 1];
                    a[i][j] = -1;
                } else {
                    a[i][j - 1] = a[i][j];
                    a[i][j]     = -1; //标记为空
                }
            }
        }
    }
}
void Right() {
    for (int i = 0; i < n; i++) {
        for (int j = m - 1 - 1; j >= 0; j--) {
            if(a[i][j] == 0)continue;
            if(a[i][j] == -1)continue;
            if (a[i][j + 1] != 0) {
                if (a[i][j + 1] != -1) {
                    a[i][j + 1] += a[i][j];
                    ans += a[i][j + 1];
                    a[i][j] = -1;
                } else {
                    a[i][j + 1] = a[i][j];
                    a[i][j]     = -1; //标记为空
                }
            }
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    string ml;
    cin >> ml;
    for (int i = 0; i < ml.length(); i++) {
        switch (ml[i]) {
            {
            case 'U':
                ans = 0;
                Up();
                break;
            case 'D':
                ans = 0;
                Down();
                break;
            case 'L':
                ans = 0;
                Left();
                break;
            case 'R':
                ans = 0;
                Right();
                break;
            default:
                break;
            }
        }
//        for (int i = 0; i < m; i++)
//        {
//            for (int j = 0 ; j < m; j++) {
//                cout<<a[i][j]<<' ';
//            }
//            cout<<"\n";
//        }
        
        printf("%lld\n", ans);
    }
    return 0;
}