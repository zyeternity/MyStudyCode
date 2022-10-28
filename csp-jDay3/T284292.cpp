#include <bits/stdc++.h>
using namespace std;
vector<int> v[3];
int Check(int sin, int dou, int sum) {
    if (v[dou].size() < 2) {
        return sum - v[sin][0];
    } else if (v[sin].size() == 0) {
        return sum - v[dou][0] - v[dou][1];
    } else {
        int rem = v[sin][0];
        if (rem > (v[dou][0] + v[dou][1])) {
            rem = (v[dou][0] + v[dou][1]);
        }
        return sum - rem;
    }
}
int n;
int main() {
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        sum += num;
        if (num % 3 == 1) {
            v[1].push_back(num);
        } else if (num % 3 == 2) {
            v[2].push_back(num);
        }
    }

    sort(v[1].begin(), v[1].end());
    sort(v[2].begin(), v[2].end());
    int sum_n = sum % 3;

    if (sum_n == 0) {
        cout << sum;
    } else if (sum_n == 1) {
        cout << Check(1, 2, sum);
    } else if (sum_n == 2) {
        cout << Check(2, 1, sum);
    }

    return 0;
}