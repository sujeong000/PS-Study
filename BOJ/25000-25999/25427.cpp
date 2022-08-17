#include <iostream>
#include <string.h>

using namespace std;
typedef long long ll;

int N;
string S, keyword = "DKSH";
ll cache[100001][4];

// dp(idx, k): S[idx...]에서 찾을 수 있는 keyword[k...]의 수
ll dp(int idx, int k) {
    if (k == 4) return 1;
    if (idx == N) return 0;
    
    ll& ret = cache[idx][k];
    if (ret != -1) return ret;
    
    ret = dp(idx+1, k);
    if (S[idx] == keyword[k]) {
        ret += dp(idx+1, k+1);
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N;
    cin >> S;
    
    cout << dp(0, 0);
    
    return 0;
}
