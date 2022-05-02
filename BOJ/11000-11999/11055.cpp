#include <iostream>
#include <string.h>

using namespace std;

int N;
int arr[1001], cache[1001];

// dp(idx): arr[idx]로 시작하는 합이 가장 큰 증가 부분 수열의 합
int dp(int idx) {
    if (idx == N) return 0;
    
    int& ret = cache[idx];
    if (ret != -1) return ret;
    
    ret = arr[idx];
    for (int i=idx+1; i<N; i++) {
        if (arr[i] > arr[idx]) {
            ret = max(ret, arr[idx]+dp(i));
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i];
    
    int ans = 0;
    for (int i=0; i<N; i++) {
        ans = max(ans, dp(i));
    }
    
    cout << ans;

    return 0;
}
