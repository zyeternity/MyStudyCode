#include <bits/stdc++.h>
using namespace std;
int m;
string ans;
int maxl = 0;
string st[2000+10];
string S;
//字符串中子串出现次数
int get_numschar(string str,string sub){
	int index = 0;	//下标 
	int count = 0;	//次数 
	
	while( (index=str.find(sub,index)) < str.length() ){
		count++;
		index++;
	}
	
	return count;
}
void check(string T){
    int t = get_numschar(S,T) * T.length();
    if(t > maxl){
        maxl = t;
        ans = T;
    }
}
map<int ,bool>is_use;
void DFS(string T){
    if(T != ""){
        check(T);
    }
    for (int i = 0; i < m; i++)
    {
        if(is_use[i] == false){//没有使用过
            if(S.find(T + st[i])!=string::npos){
                is_use[i] = true;//标记
                DFS(T + st[i]);
                is_use[i] = false;//删除标记
            }
        }
    }
    
}
int main() {
    cin>>S;
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        cin>>st[i];
    }
    DFS("");
    cout<<maxl;
    return 0;
}