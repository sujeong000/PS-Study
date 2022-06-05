#include <iostream>
#include <string.h>

using namespace std;

const int INF = 987654321;

int N, K;
int coin[101];
int cache[10001];

// dp(price): 정확히 k원을 만드는데 필요한 동전의 최소 개수
int dp(int price) {
    if (price == 0) return 0;
    
    int& ret = cache[price];
    if (ret != -1) return ret;
    
    ret = INF;
    for (int i=0; i<N; i++) {
        if (coin[i] <= price) ret = min(ret, 1+dp(price-coin[i]));
    }
        
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N >> K;
    for (int i=0; i<N; i++) cin >> coin[i];
    
    int ans = dp(K);
    
    if (ans == INF) cout << -1;
    else cout << ans;

    return 0;
}
