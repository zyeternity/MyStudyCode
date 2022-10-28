#include <bits/stdc++.h>
using namespace std;

std::priority_queue<int, std::vector<int>, std::greater<int> > queB;
std::priority_queue<int, std::vector<int>, std::less<int> > queA;

int in[(int)2e5+10];

int main(){
    int m,n;
    cin>>m>>n;
    for(int i=1;i <= m;i++){
        cin>>in[i];
    }
    int now = 1;
    for (int i = 1; i <= n; i++)
    {
        int q;
        cin >> q;
        for(;now <= q;now++){
            queA.push(in[now]);
            if(queA.size() == i){
                queB.push(queA.top());
                queA.pop();
            }
        }
        cout << queB.top() << endl;
        queA.push(queB.top());
        queB.pop();
    }

    return 0;
}