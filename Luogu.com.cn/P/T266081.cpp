#include <cmath>
#include <ctime>
#include <iostream>
using namespace std;
// 时间计算函数
long long convert(int year, int mon, int day, int hour, int min, int sec,
                  int week = 0) {
    tm info;
    info.tm_year = year - 1900;
    info.tm_mon  = mon;
    info.tm_mday = day;
    info.tm_hour = hour;
    info.tm_min  = min;
    info.tm_sec  = sec;
    info.tm_wday = week;
    return mktime(&info);
}
int main() {
    int year1, mon1, day1, hour1, min1, sec1;
    int year2, mon2, day2, hour2, min2, sec2;
    string tem;
    getline(std::cin, tem);
    year1 = (tem[0] - '0') * 1000 + (tem[1] - '0') * 100 + (tem[2] - '0') * 10 +
            (tem[3] - '0') * 1;
    mon1  = (tem[5] - '0') * 10 + (tem[6] - '0') * 1;
    day1  = (tem[8] - '0') * 10 + (tem[9] - '0') * 1;
    hour1 = (tem[11] - '0') * 10 + (tem[12] - '0') * 1;
    min1  = (tem[14] - '0') * 10 + (tem[15] - '0') * 1;
    sec1  = (tem[17] - '0') * 10 + (tem[18] - '0') * 1;
    getline(std::cin, tem);
    year2 = (tem[0] - '0') * 1000 + (tem[1] - '0') * 100 + (tem[2] - '0') * 10 +
            (tem[3] - '0') * 1;
    mon2  = (tem[5] - '0') * 10 + (tem[6] - '0') * 1;
    day2  = (tem[8] - '0') * 10 + (tem[9] - '0') * 1;
    hour2 = (tem[11] - '0') * 10 + (tem[12] - '0') * 1;
    min2  = (tem[14] - '0') * 10 + (tem[15] - '0') * 1;
    sec2  = (tem[17] - '0') * 10 + (tem[18] - '0') * 1;
    long long ans =
        abs((long long)convert(year1, mon1, day1, hour1, min1, sec1) -
            (long long)convert(year2, mon2, day2, hour2, min2, sec2));
    cout << ans;
    if (ans)
        cout << "000";
    return 0;
}