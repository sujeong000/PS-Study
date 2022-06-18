#include <iostream>

using namespace std;

const int MOD = 10007;

int power(int x, int n) {
    if (n == 0) return 1;
    
    int half = power(x, n/2);
    if (n % 2) return ((half * half) % MOD) * x % MOD;
    else return half * half % MOD;
}

int moduloInverse(int x) {
    return power(x, MOD-2);
}

int factorial(int x) {
    int ret = 1;
    
    for (int i=1; i<=x; i++) {
        ret *= i;
        ret %= MOD;
    }
    
    return ret;
}

int main()
{
    int N, K;
    cin >> N >> K;
    
    int ret = factorial(N) * moduloInverse(factorial(N-K)) % MOD;
    ret = ret * moduloInverse(factorial(K)) % MOD;
    cout << ret;

    return 0;
}
