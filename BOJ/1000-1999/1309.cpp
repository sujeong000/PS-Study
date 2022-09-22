#include <iostream>
#include <string.h>

using namespace std;
const int MOD = 9901;

int N;
int cache[100001][3];

int dp(int idx, int prev) {
    if (idx == N) return 1;
    
    int& ret = cache[idx][prev];
    if (ret != -1) return ret;
    
    ret = dp(idx+1, 0);
    if (prev != 2) ret = (ret + dp(idx+1, 2)) % MOD;
    if (prev != 1) ret = (ret + dp(idx+1, 1)) % MOD;
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N;
    cout << dp(0, 0);

    return 0;
}
