#include <iostream>
#include <string.h>

using namespace std;

int N, K;
int cache[50001][3];
int arr[50001];
int sum[50001];

int dp(int idx, int n) {
    if (n == 0) return 0;
    if (idx > N-K) return 0;
    
    int& ret = cache[idx][n];
    if (ret != -1) return ret;
    
    ret = max(dp(idx+1, n), sum[idx]+dp(idx+K, n-1));
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i];
    cin >> K;
    
    for (int i=0; i<K; i++) sum[0] += arr[i];
    for (int i=1; i<N; i++) sum[i] = sum[i-1] + arr[i-1+K] - arr[i-1];
    
    cout << dp(0, 3);

    return 0;
}
