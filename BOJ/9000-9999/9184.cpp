#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

const int MAX = 21;

int cache[MAX][MAX][MAX];

int dp(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return dp(20, 20, 20);
    
    int& ret = cache[a][b][c];
    if (ret != -1) return ret;
    
    if (a < b && b < c) {
        return ret = dp(a, b, c-1) + dp(a, b-1, c-1) - dp(a, b-1, c);
    }
    
    return ret = dp(a-1, b, c) + dp(a-1, b-1, c) + dp(a-1, b, c-1) - dp(a-1, b-1, c-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    while (true) {
        int a, b, c;
        cin >> a >> b >> c;
        
        if (a == -1 && b == -1 && c == -1) {
            break;
        }
        
        cout << "w(" << a << ", " << b << ", " << c << ") = " << dp(a, b, c) << "\n";
    }
    
    return 0;
}
