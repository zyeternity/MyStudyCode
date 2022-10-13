// //vector 的内存管理
// #include <bits/stdc++.h>
// #include <conio.h>
// using namespace std;
// int main(){
//     vector<int>a;
//     cout<<sizeof(a)<<' ';
//     _getch();
//     for(int i = 0;i<100000000;i++)a.push_back(i);//存入数据
//     cout<<sizeof(a)<<' ';
//     _getch();
//     a.clear();//不清理内存
//     cout<<sizeof(a)<<' ';
//     _getch();
//     a.shrink_to_fit();//清理内存
//     cout<<sizeof(a);
//     _getch();
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int main(){
    string str = "abcde";
    string temp;
    //删除i
    int i = 1;
    temp.append(str,0,i);
    temp.append(str,i+1,str.length()-1-i);
    cout<<temp;
}