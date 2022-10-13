// #include<bits/stdc++.h>
// using namespace std;
// int T,N,M,K,L,R,Ans=-1,t;
// int read(){
// 	int ret=0,f=1;char ch=getchar();
// 	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
// 	while( isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
// 	return ret*f;
// }
// int get(int x){
// 	if(!x)return 0;
// 	return get(x/10)+1;
// }
// int Max(int a,int b){
// 	if(a>b)return a;
// 	return b;
// }
// void DFS(int x,int id,int sum,int sux,int len){
// 	if(id==len+1){
// 		if(N<=x&&x<=M&&sux>Ans&&sum==K)Ans=sux,t=x;
// 		return;
// 	}
// 	if(Ans>=0&&!sux)return;
// 	int l=Max(0,K-sum-(len-id)*9),r=min(9,K-sum);
// 	if(id==1)l=Max(l,1);
// 	for(int i=l;i<=r;i++)
// 	DFS(x*10+i,id+1,sum+i,sux*i,len);
// }
// int main(){
// 	T=read();
// 	while(T--){
// 		N=read(),M=read(),K=read(),Ans=-1;
// 		L=get(N),R=get(M);
// 		for(int i=L;i<=R;i++)DFS(0,1,0,1,i);
// 		printf("%d %d\n",t,Ans);
// 	}
// //	printf("%.4lf\n",(double)clock()/CLOCKS_PER_SEC);
// 	return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// int t,m,n,k,a[5000005],b[5000005];
// void f(int x,int &a,int &b)
// {
// 	a=0,b=1;
// 	while(x)
// 	{
// 		a+=x%10;
// 		b*=x%10;
// 		x/=10;
// 	}
// }
// int main() 
// {
// 	for(int i=1;i<=5000005;i++)
// 		f(i,a[i],b[i]);
//     cin>>t;
//     while(t--)
//     {
//     	cin>>m>>n>>k;
//     	int pos,maxi=-1;
//     	for(int i=m;i<=n;i++)
//     		if(a[i]==k&&b[i]>maxi)
//     			pos=i,maxi=b[i];
//     	cout<<pos<<" "<<maxi<<endl;;
// 	}
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int t,n,m,k,h[5000010],c[5000010],mx,ans;
// int main(){
// 	for(int i=1;i<=5000000;i++)
// 	    h[i]=h[i/10]+(i%10);
// 	for(int i=1;i<=9;i++)
// 	    c[i]=i;
// 	for(int i=10;i<=5000000;i++)
// 	    c[i]=c[i/10]*(i%10);
// 	cin>>t;
// 	while(t--){
// 		cin>>n>>m>>k;
// 		mx=ans=-1;
// 		for(int i=n;i<=m;i++)
// 		    if(h[i]==k)
// 		        if(c[i]>mx){
// 		        	ans=i;
// 					mx=c[i]; 
// 				}
// 		printf("%d %d\n",ans,mx);
// 	} 
// 	return 0;
// }
