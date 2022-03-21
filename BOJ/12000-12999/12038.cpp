#include <iostream>
#include <string.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
ll C, V, L;
ll power_C[501], power_V[501];
ll comb[501][501];

ll combination(int n, int r) {
    if (n == r || r == 0) return 1;
    
    ll& ret = comb[n][r];
    if (ret != -1) return ret;
    
    ret = (combination(n-1, r-1) + combination(n-1, r)) % MOD;
    
    return ret;
}

void calc_power() {
    ll cmul = 1, vmul = 1;
    
    for (int i=0; i<501; i++) {
        power_C[i] = cmul;
        power_V[i] = vmul;
        
        cmul = cmul * C % MOD;
        vmul = vmul * V % MOD;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(comb, -1, sizeof(comb));
    
    int T;
    cin >> T;
    
    for (int t=1; t<=T; t++) {
        cin >> C >> V >> L;
        
        calc_power();
        
        ll sum = 0;

        for (int i=0; 2*i<=L; i++) {
            ll cnt = combination(L-i, i);   // (자음+모음) i개와 모음 L-i개의 자리 정하기
            cnt = cnt * power_C[i] % MOD;   // i개의 자음 종류 정하기
            cnt = cnt * power_V[L-i] % MOD; // L-i개의 모음 종류 정하기
            
            sum = (sum + cnt) % MOD;
        }
        
        cout << "Case #" << t << ": " << sum << "\n";
    }

    return 0;
}
