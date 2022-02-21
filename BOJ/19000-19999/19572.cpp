#include <iostream>

using namespace std;

int main()
{
    double d1, d2, d3;
    cin >> d1 >> d2 >> d3;
    
    double a = (d2 + d1 - d3) / 2;
    double b = (d1 + d3 - d2) / 2;
    double c = (d2 + d3 - d1) / 2;
    
    if (a <= 0 || b <= 0 || c <= 0) {
        cout << -1 << "\n";
    }
    else {
        cout << 1 << "\n";
        printf("%.1f %.1f %.1f", a, b, c);
    }

    return 0;
}
