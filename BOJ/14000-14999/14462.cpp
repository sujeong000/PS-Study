#include <iostream>
#include <string.h>

using namespace std;

const int MAX = 1000;

int N;
int left_cows[MAX], right_cows[MAX], cache[MAX][MAX];

// dp(l, r) : left_cows[l...]과 right_cows[r...]사이에 놓을 수 있는 횡단보도의 최대 갯수
int dp(int l, int r) {
    if (l == N || r == N) return 0;
    
    int& ret = cache[l][r];
    if (ret != -1) return ret;
    
    ret = dp(l+1, r);
    for (int i=r; i<N; i++) {
        if (abs(left_cows[l] - right_cows[i]) > 4) continue;
        ret = max(ret, 1 + dp(l+1, i+1));
        break;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N;
    for (int i=0; i<N; i++) cin >> left_cows[i];
    for (int i=0; i<N; i++) cin >> right_cows[i];
    
    cout << dp(0, 0);
    
    return 0;
}
