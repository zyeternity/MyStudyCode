#include <iostream>
// #include <conio.h>
#include <cmath>
using namespace std;
#define MaxMap (100+10) 
int r, c;
int Map[MaxMap][MaxMap];
int dx[] = { 1,-1, 0, 0};
int dy[] = { 0, 0, 1,-1};

bool isf[MaxMap][MaxMap];//被搜索过
int max_f[MaxMap][MaxMap];//记忆化

int dfs(int _r,int _c){
    if(/*isf[_r][_c]*/max_f[_r][_c]){//already
        //返回搜索数值
        return max_f[_r][_c];
    }
    max_f[_r][_c] = 1;
    for (int i = 0; i < 4; i++)
    {
        int __r = _r + dx[i],__c = _c + dy[i];
        if(__r < r && __c < c && __r >= 0 && __c >= 0){
            if(Map[__r][__c] < Map[_r][_c])
                max_f[_r][_c] = max(max_f[_r][_c],dfs(__r,__c) + 1);
        }
    }
    // isf[_c][_r] = true;
    return max_f[_r][_c];//返回
}


int main()
{
    cin >> r >> c;
    for(int i = 0;i < r;i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin>>Map[i][j];
            // isf[i][j] = false;
        }    
    }
    
    int maxs = 1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout<<i<<' '<<j<<' '<<dfs(i,j)<<endl;
            maxs = max(maxs,dfs(i,j));
        }
        
    }
    printf("%d",maxs);
    //_getch();
    return 0;
}