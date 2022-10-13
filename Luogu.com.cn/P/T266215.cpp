#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        int k;
        cin>>k;
        int maxs = 0;
        for(int i = 1;i<k;i++){
            for (int j = 1; j <= i; j++)
            {  
                if(k % (i*j) == 0){
                    maxs = max(maxs,i*j * 2 + k/i * 2 + k/j * 2);
                } 
            }
            
        }
        cout<<maxs<<'\n';
    }
    return 0;
}