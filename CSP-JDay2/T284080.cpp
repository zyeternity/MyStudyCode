#include <bits/stdc++.h>
using namespace std;

double cur[100+10];

int main() {

    // freopen("T284080彩票.in","r",stdin);
    // freopen("T284080彩票.out","w",stdout);
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>cur[i];
        cur[i] = 1-cur[i];
    }
    sort(cur,cur+n,[&](double a,double b) { return a > b; });
    double lastsum = 1;
    for(int i = 0; i < n;i++){
        lastsum *= cur[i];
        printf("%.2lf\n",lastsum);
    }
    // fclose(stdin);
    // fclose(stdout);

    return 0;
}