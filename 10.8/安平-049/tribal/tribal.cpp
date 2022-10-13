#include <bits/stdc++.h>
using namespace std;

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

long long n,pos;
long long a[100000+10];
int main()
{
    freopen("tribal.in","r",stdin);
    freopen("tribal.out","w",stdout);
    n = read();
    pos = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    int ans= 0;
    if(a[pos] < a[pos-1] || a[pos] < a[pos+1]){
        ans ++;
        a[pos] = 1e9;
    }
    for (int i = pos-1; i > 0; i--)//前方是否需要修改
    {
        if(a[i] > a[i+1]){
            a[i] = a[i+1];
            ans++;
        }
    }
    for (int i = n; i > pos; i--)//后方是否需要修改
    {
        if(a[i] > a[i-1]){
             a[i-1] = a[i];
            ans++;
        }
    }
    write(ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}