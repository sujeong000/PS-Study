#include <iostream>
#include <string.h>

using namespace std;

const int MOD = 10007;

int N;
int cache[10][1001];

// dp(x, len): x보다 크거나 같은 수들로만 이루어진 길이 len짜리 오르막 수의 개수
int dp(int x, int len) {
    if (len == 1) return 10-x;
    
    int& ret = cache[x][len];
    if (ret != -1) return ret;
    
    ret = 0;
    for (int i=x; i<10; i++) {
        ret += dp(i, len-1);
        ret %= MOD;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N;
    cout << dp(0, N);

    return 0;
}
