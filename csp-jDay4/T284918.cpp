#include <bits/stdc++.h>
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
}
#include<bits/stdc++.h>
using namespace std;

const int N=110;
int f[N];
int v[N][N],w[N][N],s[N];
int n,m,k;

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s[i];
        for(int j=0;j<s[i];j++){
            cin>>v[i][j]>>w[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=m;j>=0;j--){
            for(int k=0;k<s[i];k++){    //for(int k=s[i];k>=1;k--)也可以
                if(j>=v[i][k])     f[j]=max(f[j],f[j-v[i][k]]+w[i][k]);  
            }
        }
    }
    cout<<f[m]<<endl;
}