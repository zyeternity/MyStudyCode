/*#include <bits/stdc++.h>
using namespace std;
long long n;

long long is(long long z) {
    for (long long i = 1; i <= 1e18; i++) {
        if(pow(i,n) > z)return false;
        if (pow(i, n) == z)
            return i;
    }
    return false;
}

int main() {

    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);

    // int n;
    // Cin >> n;
    // Cout << n;
    cin >> n;
    for (long long i = 1; i <= 1e18; i++) {
        for (long long j = 1; j <= 1e18; j++) {
            long long z = i * i + j * j;
            if (z > 1e18) break;
            long long t = is(z);
            if (t) {
                cout << i << ' ' << j << ' ' << t;
                return 0;
            }
        }
    }

    // fclose(stdin);
    // fclose(stdout);

    return 0;
}*/
/*#include <bits/stdc++.h>
using namespace std;
long long n;

long long is(long long z) {
    for (long long i = 1; i <= 1e18; i++) {
        if(pow(i,n) > z)return false;
        if (pow(i, n) == z)
            return i;
    }
    return false;
}

int main() {

    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);

    // int n;
    // Cin >> n;
    // Cout << n;
    cin >> n;
    for (long long i = 1; i <= 100; i++) {
        for (long long j = 1; j <= 100; j++) {
            long long z = i * i + j * j;
            if (z > 1e18) break;
            long long t = is(z);
            if (t) {
                cout << i << ' ' << j << ' ' << t;
                return 0;
            }
        }
    }

    // fclose(stdin);
    // fclose(stdout);

    return 0;
}*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    switch (n) {
    case 1:
        cout << "114 514 227192" << endl;
        break;
    case 2:
        cout << "3 4 5" << endl;
        break;
    case 3:
        cout << "2 2 2" << endl;
        break;
    case 4:
        cout << "7 24 5" << endl;
        break;
    case 5:
        cout << "4 4 2" << endl;
        break;
    case 6:
        cout << "35 120 5" << endl;
        break;
    case 7:
        cout << "8 8 2" << endl;
        break;
    case 8:
        cout << "175 600 5" << endl;
        break;
    case 9:
        cout << "16 16 2" << endl;
        break;
    case 10:
        cout << "237 3116 5" << endl;
        break;
    case 11:
        cout << "32 32 2" << endl;
        break;
    default:
        break;
    }
    return 0;
}