#include <bits/stdc++.h>
using namespace std;
struct s {
    string id;
    int ah, am, as, ass;
    int bh, bm, bs, bss;
    string thing;
} zm[10000 + 10];
int cut = 0;
int main() {
    string kkk;
    cin >> kkk;
    while (true) {
        if (kkk == "#") {
            break;
        }
        if (kkk == "") {
            getline(cin, kkk);
            continue;
        }
        zm[cut].id = kkk;
        scanf("%d:%d:%d,%d --> %d:%d:%d,%d", &zm[cut].ah, &zm[cut].am,
              &zm[cut].as, &zm[cut].ass, &zm[cut].bh, &zm[cut].bm, &zm[cut].bs,
              &zm[cut].bss);
        zm[cut].thing = "";
        getline(cin, kkk);
        while (kkk != "" && kkk != "#") {
            zm[cut].thing += kkk;
            zm[cut].thing += '\n';
            getline(cin, kkk);
        }
        cout << endl;
        cout << zm[cut].id << endl
             << ' ' << zm[cut].ah << ' ' << zm[cut].am << ' ' << zm[cut].as
             << ' ' << zm[cut].ass << endl
             << ' ' << zm[cut].bh << ' ' << zm[cut].bm << ' ' << zm[cut].bs
             << ' ' << zm[cut].bss << endl;
        cout << ' ' << endl;

        cut++;
    }
    int addtime;
    scanf("%d", &addtime);

    system("pause");
    return 0;
}