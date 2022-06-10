#include <iostream>

using namespace std;

struct Date {
    int year, month, day;
};

bool isLeapYear(int y) {
    if ((y % 100 != 0) && (y % 4 == 0)) return true;
    else if (y % 400 == 0) return true;
    else return false;
}

int daysInMonth(int y, int m) {
    switch (m){
        case 2:
            return isLeapYear(y) ? 29 : 28;
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        default:
            return 30;
    }
}

Date dayBefore(int y, int m, int d, int diff) {
    while (diff > 0) {
        int g = min(d, diff);
        d -= g;
        diff -= g;
        
        if (d == 0) {
            if (--m == 0) {
                m = 12;
                y--;
            }
            
            d = daysInMonth(y, m);
        }
    }
    
    return {y, m, d};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while (T--) {
        int y, m; cin >> y >> m;
        Date ans = dayBefore(y, m, m, m);
        cout << ans.year << " " << ans.month << " " << ans.day << "\n";
    }

    return 0;
}
