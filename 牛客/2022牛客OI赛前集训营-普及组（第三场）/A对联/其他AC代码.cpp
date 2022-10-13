#include<bits/stdc++.h>
using namespace std;
int n,a[100007],ans[100007],cnt;
map<int,int> vis;
map<int,int> vis2;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        vis2[a[i]]=1;
    }
    for(int i=1;i<=n;i++)
        if(vis.find(a[i])!=vis.end())
            ans[i]=vis[a[i]];
        else{
            while(vis2.find((++cnt))!=vis2.end());
            vis[a[i]]=cnt;
            ans[i]=cnt;
        }
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    return 0;
}