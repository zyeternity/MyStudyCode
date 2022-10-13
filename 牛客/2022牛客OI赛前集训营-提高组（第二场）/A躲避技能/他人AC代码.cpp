// // Problem: 躲避技能
// // Contest: NowCoder
// // URL: https://ac.nowcoder.com/acm/contest/40646/A
// // Memory Limit: 524288 MB
// // Time Limit: 4000 ms
// // 
// // Powered by CP Editor (https://cpeditor.org)

// #include<bits/stdc++.h>
// typedef long long ll;
// #define rep(i, a, b) for(int i = (a); i <= (b); i ++)
// #define per(i, a, b) for(int i = (a); i >= (b); i --)
// #define Ede(i, u) for(int i = head[u]; i; i = e[i].nxt)
// using namespace std;

// inline int read() {
// 	int x = 0, f = 1; char c = getchar();
// 	while(c < '0' || c > '9') f = (c == '-') ? - 1 : 1, c = getchar();
// 	while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
// 	return x * f;
// }

// const int N = 1e5 + 10;
// int n, m, s[N], t[N];
// int cnt, head[N];
// struct node {int len, a[200]; node() {len = 0; memset(a, 0, sizeof(a));}} ans;
// struct edge {int nxt, v; node w;} e[N << 1];

// node init() {
// 	node x; char c = getchar();
// 	while(c < '0' || c > '9') c = getchar();
// 	while(c >= '0' && c <= '9') x.a[++ x.len] = c - 48, c = getchar();
// 	return x;
// }

// node plu(node x, node y) {
// 	if(! x.len) return y;
// 	node z; z.len = max(x.len, y.len);
// 	rep(i, 1, z.len)
// 		z.a[i] += x.a[i] + y.a[i], 
// 		z.a[i + 1] += z.a[i] / 10, 
// 		z.a[i] %= 10;
// 	int i = z.len + 1; while(z.a[i]) z.len = i, z.a[i + 1] += z.a[i] / 10, z.a[i] %= 10, i ++;
// 	return z;
// }

// node mul(node x, int y) {
// 	node z; z.len = x.len;
// 	rep(i, 1, z.len)
// 		z.a[i] += x.a[i] * y, 
// 		z.a[i + 1] += z.a[i] / 10, 
// 		z.a[i] %= 10;
// 	int i = z.len + 1; while(z.a[i]) z.len = i, z.a[i + 1] += z.a[i] / 10, z.a[i] %= 10, i ++;
// 	return z;
// }

// void dfs(int u, int fa, node c) {
// 	Ede(i, u) {
// 		int v = e[i].v; node w = e[i].w;
// 		if(v != fa) dfs(v, u, w), s[u] += s[v], t[u] += t[v];
// 	}
// 	if(s[u] != t[u]) ans = plu(ans, mul(c, abs(s[u] - t[u])));
// }

// void print(node x) {
// 	per(i, x.len, 1) printf("%d", x.a[i]);
// 	puts("");
// }

// int main() {
// 	n = read(), m = read();
// 	rep(i, 1, m) {int x = read(); s[x] ++;}
// 	rep(i, 1, m) {int x = read(); t[x] ++;}
// 	rep(i, 2, n) {
// 		int u = read(), v = read(); node w = init();
// 		e[++ cnt] = (edge) {head[u], v, w}, head[u] = cnt;
// 		e[++ cnt] = (edge) {head[v], u, w}, head[v] = cnt;
// 	}
// 	dfs(1, 0, ans); print(ans);
// 	return 0;
// }















// #include <cstdio>
// #include <iostream>
// #include <cstring>
// #include <algorithm>
// #include <string>
// #include <queue>
// #include <set>
// #include <cmath>
// #include <random>
// #include <cassert>
// #include <vector>
// using namespace std;

// #define ll long long
// #define llu unsigned long long
// #define mem(a, b) memset(a, b, sizeof(a))
// #define el printf("\n")
// #define pii pair<int, int>
// #define af assert(0)
// #define gc getchar()
// #define ff(x) cout<<#x<<" = "<<x<<"\n"
// #define fff(x, y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<"\n"
// #define ffff(x, y, z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<"\n"
// #define rep(i, l, r) for(int i = (l); i <= (r); ++i)
// #define dep(i, l, r) for(int i = (l); i >= (r); --i)

// const int INF = 0x3f3f3f3f;
// const int N = 1e5 + 10, M = 2e5 + 10, MAXN = 100;
// const int T = 10000;
// int sta[N];
// struct big{
//     int m[MAXN + 5] = {0};
// };
// big operator + (big x, big y){
//     rep(i, 0, MAXN){
//         x.m[i] = x.m[i] + y.m[i];
//         if(x.m[i] >= T){
//             x.m[i] -= T;
//             x.m[i + 1] += 1;
//         }
//     }
//     return x;
// }
// big operator * (big x, int y){
//     rep(i, 0, MAXN){
//         x.m[i] = x.m[i] * y;
//     }
//     rep(i, 0, MAXN){
//         if(x.m[i] >= T){
//             x.m[i + 1] += x.m[i] / T;
//             x.m[i] = x.m[i] % T;
//         }
//     }
//     return x;
// }
// big Bread(){
//     char c = gc;
//     int top = 0;
//     while(c < '0' || c > '9'){
//         c = gc;
//     }
//     while(c >= '0' && c <= '9'){
//         sta[++top] = c - '0';
//         c = gc;
//     }
//     big ans;
//     int l, r, now = 0, x;
//     for(l = 1, r = 4; r <= top; l += 4, r += 4){
//         x = 0;
//         dep(i, r, l) x = x * 10 + sta[i];
//         // ff(x);
//         ans.m[now++] = x;
//     }
//     x = 0;
//     dep(i, top, l){
//         x = x * 10 + sta[i];
//     }
//     ans.m[now++] = x;
//     return ans;
// }
// void print(big x){
//     dep(id, MAXN, 0){
//         if(x.m[id]){
//             printf("%d", x.m[id]);
//             dep(i, id - 1, 0){
//                 printf("%04d", x.m[i]);
//             }
//             break;
//         }
//     }
//     printf("\n");
// }

// int n, m, pos;
// int ver[M], nex[M], head[N], cnt[N];
// int edgeid[M];
// big val[N], cost[N];

// int read(){
//     char c = gc;
//     int top = 0;
//     while(c < '0' || c > '9'){
//         c = gc;
//     }
//     while(c >= '0' && c <= '9'){
//         sta[++top] = c - '0';
//         c = gc;
//     }
//     int ans = 0;
//     dep(i, top, 1){
//         ans = ans * 10 + sta[i];
//     }
//     return ans;
// }

// void add(int x, int y){
//     ver[++pos] = y, nex[pos] = head[x], head[x] = pos;
// }

// void dfs(int x, int fa){
//     for(int i = head[x]; i; i = nex[i]){
//         int y = ver[i];
//         if(y == fa) continue;
//         cost[y] = val[edgeid[i]];
//         dfs(y, x);
//         cnt[x] += cnt[y];
//     }
// }

// int main(){
//     // freopen("1.in", "r", stdin);
//     // freopen("my.out", "w", stdout);
//     scanf("%d %d", &n, &m);
//     rep(i, 1, m){
//         int x; scanf("%d", &x);
//         ++cnt[x];
//     }
//     rep(i, 1, m){
//         int x; scanf("%d", &x);
//         --cnt[x];
//     }
//     rep(i, 2, n){
//         int x, y;
//         scanf("%d %d", &x, &y);
//         big z = Bread();
//         // ffff(x, y, z);
//         edgeid[pos + 1] = edgeid[pos + 2] = i;
//         val[i] = z;
//         // print(z * 10);
//         add(x, y), add(y, x);
//     }
//     dfs(1, -1);
//     // int ans = 0;
//     big ans;
//     // rep(i, 1, n) printf("%d ", cnt[i]); el;
//     rep(i, 2, n){
//         int x = cnt[i] < 0 ? -cnt[i] : cnt[i];
//         ans = ans + cost[i] * x;
//     }
//     // printf("%d\n", ans);
//     print(ans);
//     return 0;
// }


















// #include<bits/stdc++.h>
// //#pragma GCC optimize(2)
// using namespace std;
// #define pii pair<int,int>
// #define ll long long
// #define il inline
// #define fst first
// #define scd second
// #define reg register
// #define err() cout<<"err "<<__LINE__<<endl,exit(0)
// #define pot(args...) \
// 	GPT(#args),cout<<"  Line "<<__LINE__<<"\t: ", \
// 	PPT(args),cout<<"\n\n"
// #define rep(i,s,t) for(int i=(s);i<=(t);++i)
// #define irep(i,t,s) for(int i=(t);i>=(s);--i)
// void PPT(){}
// template<typename TYPE,typename... TYPES>
// void PPT(const TYPE& x,const TYPES&... y){cout<<x<<' ',PPT(y...);}
// void GPT(string nam){cout<<setw(29)<<nam;}
// il int read(int x=0,int f=1){
//     char ch=getchar();
//     while(ch<'0'||ch>'9')f=(ch=='-'?-1:1),ch=getchar();
//     while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
//     return x*f;
// }
// il void write(int x){
//     char F[200];
//     int tmp=x>0?x:-x;
//     if(x<0)putchar('-');
//     if(x==0)putchar('0');
//     int cnt=0;
//     while(tmp>0){
// 	    F[cnt++]=tmp%10+'0';
//         tmp/=10;
//     }
//     while(cnt>0)putchar(F[--cnt]);
// }
// const int N=1e5+10;
// struct Big{
// 	int sz,w[130];
// 	Big(){
// 		sz=0;
// 		memset(w,0,sizeof(w));
// 	}
// 	void read(){
// 		sz=0;
// 		char c=getchar();
// 		while(c<'0'||c>'9')c=getchar();
// 		while('0'<=c&&c<='9'){
// 			w[sz++]=c-'0';
// //			pot(sz,w[sz-1]);
// 			c=getchar();
// 		}
// 	}
// 	int& operator[](int x){return w[x];}
// 	Big operator+(Big b){
// 		Big r;
// 		r.sz=0;
// 		r[0]=w[0]+b[0];
// 		if(r[0])r.sz=1;
// 		rep(i,1,max(sz,b.sz)+1){
// 			r[i]=r[i-1]/10+w[i]+b[i];
// 			r[i-1]%=10;
// 			if(r[i])r.sz=max(r.sz,i+1);
// 		}
// 		return r;
// 	}
// 	void write(){
// 		irep(i,sz-1,0)putchar('0'+w[i]);
// 		putchar('\n');
// 	}
// }w[N];
// Big mul(Big a,int b){
// 	Big r;
// 	r.sz=a.sz;
// 	rep(i,0,a.sz-1){
// 		r[i]+=a[i]*b;
// 		r[i+1]+=r[i]/10;
// 		r[i]%=10;
// 	}
// 	while(r.sz>0&&r[r.sz-1]>9){
// 		r.sz++;
// 		r[r.sz-1]+=r[r.sz-2]/10;
// 		r[r.sz-2]%=10;
// 	}
// 	return r;
// }
// int n,m,cnt[N],need[N],dep[N],fa[N];
// int adid[N];
// vector<pii>to[N];
// vector<int>son[N];
// void dfs1(int u){
// 	for(pii e:to[u]){
// 		if(e.fst==fa[u])continue;
// 		son[u].push_back(e.fst);
// 		fa[e.fst]=u;
// 		dep[e.fst]=dep[u]+1;
// 		adid[e.fst]=e.scd;
// 		dfs1(e.fst);
// 	}
// }
// void add(pii &a,pii b){
// 	a.fst+=b.fst;
// 	a.scd+=b.scd;
// }
// void clr(pii &a){
// 	int x=min(a.fst,a.scd);
// 	a.fst-=x;a.scd-=x;
// }
// int get_v(pii a){
// 	return a.fst+a.scd;
// }
// Big res;
// pii get(int u){
// 	pii cur(cnt[u],need[u]);
// 	clr(cur);
// //	pot(u,cur.fst,cur.scd);
// 	for(int v:son[u]){
// //		pot(v);
// 		pii nxt=get(v);
// 		add(cur,nxt);
		
// 		res=res+mul(w[adid[v]],get_v(nxt));
// 	}
// 	clr(cur);
// 	return cur;
// }
// signed main(){
// //	ios::sync_with_stdio(false);
// //	Big a,b;int c;
// //	a.read(),b.read(),c=read();
// //	Big d=a+b,e=mul(b,c);
// //	d.write();e.write();
// 	cin>>n>>m;
// 	rep(i,1,m){
// 		int pos=read();
// 		cnt[pos]++;
// 	}
// 	rep(i,1,m){
// 		int pos=read();
// 		need[pos]++;
// 	}
// 	rep(i,1,n-1){
// 		int u=read(),v=read();
// 		w[i].read();
// //		w[i].write();
// 		to[u].push_back(pii(v,i));
// 		to[v].push_back(pii(u,i));
// 	}
// 	dep[1]=1;
// 	dfs1(1);
// 	get(1);
// 	res.write();
// }
