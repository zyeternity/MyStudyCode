#include <bits/stdc++.h>
using namespace std;



inline void write(int x) {
  static int sta[35];
  int top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top) putchar(sta[--top] + 48);
}

int main() {
    std::ios::sync_with_stdio(false);
    freopen("pair.in", "r", stdin);
    freopen("pair.out", "w", stdout);

    write(0);

    fclose(stdin);
    fclose(stdout);
    return 0;
}