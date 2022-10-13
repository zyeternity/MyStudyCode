// #include <algorithm>
// #include <cstdio>
// #include <iostream>
// #include <list>
// #include <map>
// #include <queue>
// #include <set>
// #include <stack>
// #include <string>
// #include <vector>
#include <bits/stdc++.h>

using namespace std;
#define Max 100000 + 10

int n;
int A[Max];
long long Ans;

int main() {
    freopen("score.in", "r", stdin);
    freopen("score.out", "w", stdout);
    Ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        Ans += A[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int las = A[i];
        for (int j = i + 1; j < n; j++) {
            las += A[j];
            Ans += las;
        }
    }
    printf("%d", Ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}