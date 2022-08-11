#include <iostream>
#include <string.h>

using namespace std;

typedef long long ll;

int cache[100001];

// dp(n): n을 제곱수들의 합으로 표현할 때에 그 항의 최소 개수
int dp(int n) {
    if (n <= 1) return n;
    
    int& ret = cache[n];
    if (ret != -1) return ret;
    
    ret = n;
    
    for (ll i=1; i*i<=n; i++) {
        ret = min(ret, 1 + dp(n-i*i));
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    int N;
    
    cin >> N;
    cout << dp(N);

    return 0;
}
