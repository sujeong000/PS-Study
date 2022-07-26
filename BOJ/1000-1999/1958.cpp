#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

string A, B, C;
int cache[101][101][101];

int dp(int a, int b, int c) {
    if (a == A.size() || b == B.size() || c == C.size()) return 0;
    
    int& ret = cache[a][b][c];
    if (ret != -1) return ret;
    
    if (A[a] == B[b] && B[b] == C[c]) {
        ret = 1 + dp(a+1, b+1, c+1);
    }
    else {
        ret = max(dp(a+1, b, c), max(dp(a, b+1, c), dp(a, b, c+1)));
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> A >> B >> C;
    cout << dp(0, 0, 0);

    return 0;
}
