#include <iostream>
#include <string.h>

using namespace std;

const int MOD = 15746;

int N;
int cache[1000001];

int dp(int n) {
    if (n < 2) return 1;
    
    int& ret = cache[n];
    if (ret != -1) return ret;
    
    ret = (dp(n-2) + dp(n-1)) % MOD;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N;
    cout << dp(N);
    
    return 0;
}
