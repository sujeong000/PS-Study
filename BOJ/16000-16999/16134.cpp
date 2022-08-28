#include <iostream>

using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

ll power(int a, int n) {
    if (n == 0) return 1;
    
    ll half = power(a, n/2);
    if (n % 2 == 0) return half * half % MOD;
    else return (half * half % MOD) * a % MOD;
}

int moduloInverse(int n) {
    return power(n, MOD-2);
}

int combination(int n, int r) {
    ll ret = 1;
    
    for (int i=0; i<r; i++) {
        ret = ret * (n-i) % MOD;
    }
    
    for (int i=r; i>=1; i--) {
        ret = ret * moduloInverse(i) % MOD;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, R;
    cin >> N >> R;
    
    cout << combination(N, R);

    return 0;
}
