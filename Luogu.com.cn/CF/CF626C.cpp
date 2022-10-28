#include<bits/stdc++.h>
using namespace std;
long long n,m,t,a[int(1e5+100)];
long long l=0,r=6000000;
int main(){
	cin>>n>>m;
	
	while(l+1<r){
		int mid=(l+r)/2;
		if(mid/2>=n&&mid/3>=m&&mid/2+mid/3-mid/6>=m+n){
			r=mid;
		}else {
			l=mid;
		}
	}
	if(l/2>=n&&l/3>=m&&l/2+l/3-l/6>=m+n){
		cout<<l<<'\n';
	}else{
		cout<<r<<'\n';
	}
	return 0;
}
