#include <iostream>
#include <string.h>

using namespace std;

const int MAX = 100001, FRI = 4, MON = 0;

int N;
int A[MAX], cache[MAX][7];

// dp(idx, k): 현재 k요일이고, idx번째~마지막 일까지 남아있을 때 금요일에 정확히 일을 끝마치는 것이 가능한지
int dp(int idx, int k) {
    if (idx == N) {
        if (k == FRI) return 1;
        else return 0;
    }
    
    int& ret = cache[idx][k];
    if (ret != -1) return ret;
    
    ret = dp(idx+1, k) + dp(idx+1, (k+A[idx])%7);
    if (ret > 0) ret = 1;
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N;
    for (int i=0; i<N; i++) cin >> A[i];
    
    if (dp(0, MON)) cout << "YES";
    else cout << "NO";
    
    return 0;
}
