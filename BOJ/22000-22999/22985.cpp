#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

typedef long long ll;

ll N, M;
string S;
ll MOD = 1000000007;
ll cache[7501][2][300];

// dp(cnt, idx) = 남은 조작 횟수가 cnt이고, 'z'의 등장여부가 z일 때, 부분문자열 S[idx...]를 조작해서 나올 수 있는 가짓수
ll dp(int cnt, int z, int idx) {
    if (idx == N-1) {
        // 'z'가 나온 적이 있으면 마지막 문자에 남은 조작수를 몰빵하지 않아도 됨.
        // 그 'z'를 활용해서 원하는 만큼만 조작이 가능.
        if (z) return 1 + min('z' - S[idx], cnt);
        else return 1;
    }
    if (cnt == 0) return 1;
    
    ll& ret = cache[cnt][z][idx];
    if (ret != -1) return ret;
    
    ret = 0;
    
    // idx번째 문자에 0번~min(z-S[idx], cnt)번의 조작을 전부 가해봄.
    for (int i=0; i <= min('z'- S[idx], cnt); i++) {
        if (i == 'z' - S[idx]) ret += dp(cnt-i, 1, idx+1);  // idx번 문자를 z로 만드는 경우
        else ret += dp(cnt-i, z, idx+1);

        ret %= MOD;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(cache, -1, sizeof(cache));

    cin >> N >> M >> S;
    
    cout << dp(min((ll)7500, M), 0, 0);

    return 0;
}
