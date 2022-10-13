#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[2000];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    int f[2000];
	fill(f,f+2000,1);
	int res = 0;	
	for(int i =1;i< n;i++){
		for(int j = 0;j<i;j++){
			if(arr[i] <= arr[j]){
				f[i] = max(f[i],f[j]+1);				
			}			
		}
		res = max(res,f[i]);
	} 
    cout<<res;
    return 0;
}