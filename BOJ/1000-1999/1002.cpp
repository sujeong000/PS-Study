#include <iostream>

using namespace std;

int T, x1, y1, r1, x2, y2, r2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    while (T--) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        
        if (r1 > r2) {
            swap(x1, x2);
            swap(y1, y2);
            swap(r1, r2);
        }
        
        int d = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        int rm = (r2-r1)*(r2-r1);
        int rp = (r1+r2)*(r1+r2);
        
        if (d == rp) cout << 1;                     // 외접
        else if (d == rm && d != 0) cout << 1;      // 내접
        else if (d == 0 && r1 == r2) cout << -1;    // 일치
        else if (d > rp || d < rm) cout << 0;       // 만나지 않음
        else cout << 2;                             // 두 점에서 만남
        
        
        cout << "\n";
    }

    return 0;
}
