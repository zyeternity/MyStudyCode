// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// using namespace std;
// const int MAXN = 1005;

// int n, flag, ans;
// int pre[MAXN]; 
// int main() {
// 	scanf("%d", &n);
// 	for (int i = 1; i <= n; i++) {
// 		scanf("%d", &pre[i]);
// 		if (pre[i] >= 240) flag = 1;//必然会被抓，直接摆烂 
// 		pre[i] += pre[i - 1];//维护前缀 
// 	}
// 	//两个策略，1是一直把事情干完然后回去被抓
// 	//2是绝对不要被抓，如果必然会被抓那么还不如一直留着不走
// 	if (flag == 0) {//还有希望 
// 		int last = 0;
// 		for (int i = 1; i <= n; i++) {
// 			if (pre[i] - pre[last] >= 240) {//已经大于了
// 				last = i - 1;//i - 1肯定不会大于，最多到i-1
// 				ans += 400;//ans加上往返 
// 			}
// 		}
// 		ans = min(ans, 10080);//如果摆烂更快 
// 	} else ans = 10080;//直接摆烂，没有挣扎必要
	
// 	ans += pre[n] + 400;
// 	printf("%d", ans);
// 	return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// int n,a[1005],s=0,cnt=0,ans=0;
// int main() 
// {
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//     	cin>>a[i];
//     	ans+=a[i];
//     	if(a[i]>=240) cnt+=100; 
// 		if(a[i]+s>=240)
// 		{
// 			cnt++;
// 			s=0;
// 		}
// 		s+=a[i];
// 	}
//     cout<<min(cnt*400,10080)+400+ans<<endl;	
//     return 0;
// }


// #include<bits/stdc++.h>
// #define maxN 10005
// #define gl 10080
// #define maxtime 240
// #define time 400
// using namespace std;
// long long n,a[maxN];
// long long f[maxN],ans,tmp1=0,tmp2=0;

// int main(){
//     cin>>n; 
//     for(int i=1;i<=n;i++){
//        cin>>a[i];
//         f[i]=f[i-1]+a[i];  
//         if(a[i]>=maxtime&&ans==0) ans+=gl;
//     }
//     if(ans==gl) ans+=f[n]+time;
//     else{
//         tmp1=time+gl+f[n];
//         long long r=1,le=0;
//         while(r<=n){
//             if(f[r]-f[le]>=maxtime){
//                 tmp2+=time;
//                 le=r-1;
//             }
//             r++;
//           }
// 	    tmp2+=time+f[n];
//        ans=min(tmp1,tmp2);
//     }
//     printf("%lld",ans);
//     return 0;
// }