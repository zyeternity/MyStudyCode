#include<bits/stdc++.h>
using namespace std;
int main(){
    char x[1000];
    int y;
    cin>>x>>y;
	sort(x,x+strlen(x));
	bool intadwha = 0;
	for(int i = 0;i<strlen(x)-y;i++){
	    if(x[i] != '0'){
	        intadwha = 1;
	    }
	    if(x[i] != '0' || !intadwha)
		    cout<<x[i];
	}
    return 0;
}