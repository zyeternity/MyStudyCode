#include <bits/stdc++.h>
using namespace std;

int main() {

    // freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);

    // int n;
    // Cin >> n;
    // Cout << n;
    // 现存可用的元素
    set<int> available;
    // 需要大于等于的值
    available.insert(1);
    available.insert(2);
    available.insert(3);
    // 查找最小的大于等于x的元素
    set<int>::iterator it = available.begin();
    if (it != available.end()){
        // 找到了这样的元素，将其从现存可用元素中移除
        cout << *it << endl;
        available.erase(it);
        // 进行相应操作……
    }

    // fclose(stdin);
    // fclose(stdout);

    return 0;
}