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
  while (top) putchar(sta[--top] + 48);  // 48 是 '0'
}
int n, t;
struct T4 {
    int id;
    int d;
} a[1000][1000];
int m[1000];
map<int,bool> next_t[1000];
int now = 0;
int main() {
    n = read();t = read();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j].id = j;
            a[i][j].d = read();
        }
        sort(a[i], a[i] + n, [&](T4 a, T4 b) { return a.d > b.d; });
    }

    for (int i = 0; i < n; i++) {
        cin >> m[i];
        for (int j = 0; j < m[i]; j++) {
            next_t[i][read()] = true;
        }
    }
    for (int i = 0; i < t; i++) {
        if (i + 1 == t - 1) { //下一位爆炸
            for(int j = 0;j<n;j++){
                if(next_t[now][a[now][j].id]){
                    now = a[now][j].id;
                    break;
                }
            }
        }else{
            int k = t - i - 1;//剩余多少次爆炸
            int ts = k % m[now];//应该传到第几个仇恨值
            int j = 0;//第几名？
            for (int s = 0; s < m[now]; s++)
            {
                if(next_t[now][a[now][s].id]){
                    j++;
                }
                if(j == ts){
                    now = a[now][s].id;
                }
            }
            
        }
    }

    write(now);
    return 0;
}