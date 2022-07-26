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
        ret = 0;
        
        for (int i=0; i<2; i++) {
            for (int j=0; j<2; j++) {
                for (int k=0; k<2; k++) {
                    if (i == 0 && j == 0 && k == 0) continue;
                    ret = max(ret, dp(a+i, b+j, c+k));
                }
            }
        }
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
