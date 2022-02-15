#include <iostream>

using namespace std;

long long MOD = 1000000007;
long long N, K;

long long pow(long long n, long long x) {
    if (x == 1) return n % MOD;
    
    long long half = pow(n, x/2);
    
    if (x % 2 == 0) {
        return half * half % MOD;
    }
    else {
        return ((half * half % MOD) * n) % MOD;
    }
}

long long modularInverse(long long n) {
    return pow(n, MOD - 2);
}

long long factorial(long long n) {
    long long ret = 1;
    
    for(int i=1; i<=n; i++) {
        ret *= i;
        ret %= MOD;
    }
    
    return ret;
}

int main()
{
    cin >> N >> K;
    
    long long A = factorial(N);
    long long B = factorial(N - K);
    long long C = factorial(K);
    
    cout << A * modularInverse(B * C % MOD) % MOD;
    
    return 0;
}

