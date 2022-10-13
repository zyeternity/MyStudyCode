#include <bits/stdc++.h>
using namespace std;

long long read() {
  long long x = 0, w = 1;
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

void check(long long n){
    bool is = 1;
    for(long long i=2; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            write(1);
            is = 0;
            break;
        }
    }
    if(is)write(0);
    printf("\n");
}
long long n;
int main()
{
    freopen("division.in","r",stdin);
    freopen("division.out","w",stdout);
    n = read();
    check(n);
    fclose(stdin);
    fclose(stdout);
    return 0;
}