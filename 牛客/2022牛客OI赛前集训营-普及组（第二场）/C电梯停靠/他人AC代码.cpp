// #include <bits/stdc++.h>
// using namespace std;
// int n, m, x, y, a[1000005], cnt;
// long long ans;
// int main()
// {
// 	scanf("%d%d", &n, &m);
// 	for(int i = 1; i <= m; i++)
// 		scanf("%d%d", &x, &y), ans += abs(x - y), a[++cnt] = x, a[++cnt] = y;
// 	sort(a + 1, a + cnt + 1);
// 	printf("%d ", a[cnt >> 1]);
// 	for(int i = 1; i <= cnt; i++)
// 		ans += abs(a[i] - a[cnt >> 1]);
// 	printf("%lld\n", ans);
// 	return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=5e5+7;
// int n,m,a,b,ans=1e18,sum,pos;
// int pre[N],pre1[N],suf[N],suf1[N];
// signed main(){
//     scanf("%lld%lld",&n,&m);
//     for(int i=1;i<=m;i++){
//         scanf("%lld%lld",&a,&b);
//         pre[a-1]+=2;
//         suf[b+1]+=2;
//         sum+=(b-a)*2;
//     }
//     for(int i=n;i>=1;i--){
//         pre[i]+=pre[i+1];
//         pre1[i]=pre1[i+1]+pre[i];
//     }
//     for(int i=1;i<=n;i++){
//         suf[i]+=suf[i-1];
//         suf1[i]=suf1[i-1]+suf[i];
//         if(suf1[i]+pre1[i]<ans){
//             ans=suf1[i]+pre1[i];
//             pos=i;
//         }
//     }
//     printf("%lld %lld",pos,ans+sum);
//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;
// int n, m, a, b;
// long long ans = 1e18+9, id, sum = 0;
// int main(){
//     cin >> n >> m;
//     vector<long long>a1(n+9), b1(n+9), A(n+9), B(n+9);
//     while(m--){
//         cin >> a >> b;
//         a1[a-1] += 2;
//         b1[b+1] += 2;
//         sum += (b - a) * 2;
//     }
//     for(int i = n; i >= 1; i--){
//         a1[i] += a1[i+1];
//         A[i] = A[i+1] + a1[i];
//     }
//     for(int i = 1; i <= n; i++){
//         b1[i] += b1[i-1];
//         B[i] += B[i-1] + b1[i];
//         if(B[i] + A[i] < ans){
//             id = i;
//             ans = B[i] + A[i];
//         }
//     }
//     cout << id << " " << ans + sum << endl;
// } 