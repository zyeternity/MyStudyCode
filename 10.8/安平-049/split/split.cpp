#include <bits/stdc++.h>
using namespace std;

#define Max 1010

int read() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') { 
    if (ch == '-') w = -1;     
    ch = getchar();              
  }
  while (ch >= '0' && ch <= '9') { 
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * w;
}
inline void write(int x) {
  static int sta[35];
  int top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top) putchar(sta[--top] + 48);
}

int n;
int k_num[10000+10];
long long ans = 0;
int main()
{
    freopen("split.in","r",stdin);
    freopen("split.out","w",stdout);
    n = read();
    for (int i = 0; i < n; i++)
    {
        k_num[read()] ++;//tong
    }
    for (int i = 0; i < k_num[0]/*0的次数*/; i++)
    {
        for (int j = 1; j <= Max; j++)
        {
            if(k_num[j]>0){
                k_num[j] --;
            }else {
                ans += j;
                break;
            }
        }
        
    }
    write(ans);
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}