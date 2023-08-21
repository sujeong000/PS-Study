#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

const int MOD = 1e9+3;

int N, K;
int cache[1001][1001];

// dp(n, k): 일렬로 놓인 N개의 색상들 중에서 k개의 색상을 인접하지 않도록 고르는 경우의 수
int dp(int n, int k) {
    if (n <= 0) {
        return (k == 0) ? 1 : 0;
    }
    
    int& ret = cache[n][k];
    if (ret != -1) return ret;
    
    // 선택하는 경우에는 다음 것을 건너 뛰고 k-1개 더 골라야 함
    return ret = (dp(n-1, k) + dp(n-2, k-1)) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(cache, -1, sizeof(cache));
    
    cin >> N >> K;
    // 0번 색상을 고르는 경우, 1번과 N-1번은 무조건 고르지 않아야 함 -> 2~(N-2)번에서 K-1개 고르기
    // 0번 색상을 고르지 않는 경우 -> 1~(N-1)번에서 K개 고르기
    cout << (dp(N-3, K-1) + dp(N-1, K)) % MOD;
    
    return 0;
}
