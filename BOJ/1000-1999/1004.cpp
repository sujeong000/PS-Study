#include <iostream>

using namespace std;

int T, N, x1, y1, x2, y2;

bool check(int x, int y, int cx, int cy, int r) {
    return (cx-x)*(cx-x) + (cy-y)*(cy-y) < r*r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    while (T--) {
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> N;
        
        int cx, cy, r, cnt = 0;
        for (int i=0; i<N; i++) {
            cin >> cx >> cy >> r;
            int res1 = check(x1, y1, cx, cy, r);
            int res2 = check(x2, y2, cx, cy, r);
            
            if ((res1 && !res2) || (!res1 && res2)) cnt++;
        }
        
        cout << cnt << "\n";
    }

    return 0;
}
