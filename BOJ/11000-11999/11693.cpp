#include <iostream>

using namespace std;

typedef long long ll;
const int MOD = 1000000007;

int N, M;

ll pow(ll x, ll n) {
    if (n == 1) return x % MOD;
    
    ll half = pow(x, n/2);
    if (n % 2 == 0) return half * half % MOD;
    else return (half * half % MOD) * x % MOD;
}

ll modulo_inverse(ll x) {
    return pow(x, MOD-2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    ll ans = 1;
    ll original_N = N;
    
    for (ll i=2; i*i<=original_N; i++) {
        if (N % i != 0) continue;
        
        ll cnt = 0;
        while (N % i == 0) {
            N /= i;
            cnt++;
        }
        
        ans = ans * (pow(i, cnt*M+1) - 1) % MOD;
        ans = ans * modulo_inverse(i-1) % MOD;
    }
    
    if (N > 1) {
        ans = ans * (pow(N, M+1) - 1) % MOD;
        ans = ans * modulo_inverse(N-1) % MOD;
    }
    
    cout << ans;

    return 0;
}
