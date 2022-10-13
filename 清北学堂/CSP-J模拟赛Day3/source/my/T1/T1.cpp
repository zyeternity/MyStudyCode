#include <bits/stdc++.h>
using namespace std;
#define u Connections[0]
#define v Connections[1]
#define w longer
#define h like_i
int m,n;
struct way{
    int Connections[2];
    int like_i;
    int longer;
    way *pu;
    way *pv;
}ways[100000];
bool iswent[100000];
void BFS(int he,int ve){
    queue<int>id;
    id.push(he);
    memset(iswent,false,sizeof(iswent));
    iswent[he] = true;
    int min = 1000000000,like;
    while(!id.empty()){
        

    }
}
int main() {
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        cin>>ways[i].u>>ways[i].v>>ways[i].w>>ways[i].h;
        ways[i].pu = &ways[ways[i].u];
        ways[i].pv = &ways[ways[i].v];
    }


    return 0;
}