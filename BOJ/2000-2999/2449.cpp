#include <iostream>
#include <string.h>

using namespace std;

const int INF = 987654321;

int N, K;
int A[200];
int cache[200][200];

// dp(lo, hi): 구간 A[lo...hi]를 모두 같은 색깔로 만드는 최소 비용
int dp(int lo, int hi) {
    if (lo == hi) return 0;
    
    int& ret = cache[lo][hi];
    if (ret != -1) return ret;
    
    ret = INF;
    for (int i=lo; i<hi; i++) {
        int m = A[lo] == A[i+1] ? 0 : 1;
        ret = min(ret, dp(lo, i) + dp(i+1, hi) + m);
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N >> K;
    for (int i=0; i<N; i++) cin >> A[i];
    
    cout << dp(0, N-1);

    return 0;
}
