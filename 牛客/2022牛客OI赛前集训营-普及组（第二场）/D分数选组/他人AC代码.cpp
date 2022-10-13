// #include <bits/stdc++.h>
// using namespace std;
// const int N = 2e3 + 5, M = (1 << 11) - 1, INF = 0x3f3f3f3f;
 
// int n, m, a[N];
// vector<int> nums[N];
// int f[N][M + 5], w[N][M + 5], dp[N];
// int main() {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++) {
//         int x, y;
//         cin >> x >> y;
//         nums[y].push_back(x);
//     }
//     for (int i = 1; i <= n; i++)
//             for (int j = 1; j <= M; j++)
//                     f[i][j] = INF;
//     for (int k = 1; k <= 2000; k++) {
//         if (!nums[k].size()) continue;
//         f[1][nums[k][0]] = 1;
//         int size = nums[k].size();
//         for (int i = 2; i <= size; i++) {
//             f[i][nums[k][i - 1]] = 1;
//             for (int j = 1; j <= M; j++)
//                 if (f[i - 1][j] != INF)
//                     f[i][j] = min(f[i][j], f[i - 1][j]), f[i][j ^ nums[k][i - 1]] = min(f[i][j ^ nums[k][i - 1]], f[i - 1][j] + 1);
//         }
//         for (int i = M; i; i--)
//             if (f[size][i] != INF && !w[k][f[size][i]]) w[k][f[size][i]] = i;
//         for (int i = 1; i <= size; i++)
//             for (int j = 1; j <= M; j++)
//                 f[i][j] = INF;
//     }
//     for (int i = 1; i <= 2000; i++)
//         for (int j = m; j; j--)
//             for (int l = 1; l <= j && l <= nums[i].size(); l++)
//                 dp[j] = max(dp[j], dp[j - l] + w[i][l]);
//     cout << dp[m] << endl;
//     return 0;
// }



// #include<bits/stdc++.h>
// #define N 2500
// using namespace std;
// int n,m,x,y,f[N][N],s[N],dp[N][N],cnt,ans;
// vector<int> ak[N],st;
// int vis[N];
// void pre(vector<int>&a){
// 	memset(f,0x3f,sizeof f);
// 	memset(s,0xC0,sizeof s);
// 	f[0][0]=0;
// 	for(int i=1;i<=a.size();i++)
// 	    for(int j=0;j<2048;j++)
// 	        f[i][j]=min(f[i-1][j],f[i-1][j^a[i-1]]+1);
// 	for(int i=0;i<2048;i++)
// 	    if(f[a.size()][i]<=m)
// 	        s[f[a.size()][i]]=max(s[f[a.size()][i]],i);
// }
// int main(){
// 	cin>>n>>m;
// 	for(int i=1;i<=n;i++){
// 		cin>>x>>y;
// 		ak[y].emplace_back(x);
// 		if(!vis[y]){
// 			vis[y]=true;
// 			st.emplace_back(y);
// 		}
// 	}
// 	memset(dp,0xC0,sizeof dp);
// 	dp[0][0]=0;
// 	for(int i=1;i<=st.size();i++){
// 		int ac=st[i-1];

// 		pre(ak[ac]);
// 		for(int j=0;j<=m;j++){
// 			dp[i][j]=dp[i-1][j];
// 		    for(int k=0;k<=ak[ac].size()&&k<=j;k++)
// 		        dp[i][j]=max(dp[i][j],dp[i-1][j-k]+s[k]);
// 		    ans=max(ans,dp[i][j]);
// 	    }
// 	}
// 	printf("%d",ans);
// 	return 0;
// } 





// #include <iostream>
// #include <cstring>
// #include <vector>
// #include <set>
// #include <map>
// using namespace std;
// const int N = 2100;
// int f[N][N], s[N], n, m, dp[N][N];
// vector<int> a[N],st;
// map<int,int> mp;
// void pre(vector<int> &a) {
//     memset(s, 0xC0, sizeof s);
//     memset(f, 0x3F, sizeof f);
//     f[0][0] = 0;
//     for (int i = 1; i <= a.size(); ++i)
//         for (int j = 0; j < 2048; ++j)
//             f[i][j] = min(f[i-1][j], f[i-1][j^a[i-1]] + 1);
//     for (int i = 0; i < 2048; ++i)
//         if (f[a.size()][i] <= m) s[ f[a.size()][i] ] = i;
// }
// int main() {
//     scanf("%d%d", &n, &m);
//     for (int i = 1, x, y; i <= n; ++i) {
//         scanf("%d%d", &x, &y);
//         a[y].emplace_back(x);
//         if(mp[y]==0) st.push_back(y),mp[y]=1;
//     }
//     memset(dp, 0xC0, sizeof dp);
//     dp[0][0] = 0;
//     for (int i = 1; i <= st.size(); ++i) {
//         pre(a[st[i-1]]);
//         for (int j = 0; j <= m; ++j){
//             dp[i][j]=dp[i-1][j];
//             for (int k = 0; k<=a[st[i-1]].size() && k<=j; ++k)
//                 dp[i][j] = max(dp[i][j], dp[i-1][j-k]+s[k]);
//         }        
//     }
//     int ans=0;
//     for(int i=1;i<=m;i++){
//         ans=max(ans,dp[st.size()][i]);
//     }
//     cout<<ans<<endl;
//     return 0;
// }