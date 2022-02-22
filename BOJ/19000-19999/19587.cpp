#include <iostream>

using namespace std;

typedef pair<long long, long long> pll;
typedef pair<pll, pll> matrix22;

long long MOD = 1000000007;
long long N;
matrix22 A = {{1, 2}, {1, 1}};

matrix22 multiply(matrix22 a, matrix22 b) {
    matrix22 ret = {{0, 0}, {0, 0}};
    
    ret.first.first += a.first.first * b.first.first % MOD; ret.first.first %= MOD;
    ret.first.first += a.first.second * b.second.first % MOD; ret.first.first %= MOD;
    
    ret.first.second += a.first.first * b.first.second % MOD; ret.first.second %= MOD;
    ret.first.second += a.first.second * b.second.second % MOD; ret.first.second %= MOD;
    
    ret.second.first += a.second.first * b.first.first % MOD; ret.second.first %= MOD;
    ret.second.first += a.second.second * b.second.first % MOD; ret.second.first %= MOD;
    
    ret.second.second += a.second.first * b.first.second % MOD; ret.second.second %= MOD;
    ret.second.second += a.second.second * b.second.second % MOD; ret.second.second %= MOD;
    
    return ret;
}

matrix22 power(long long n) {
    if (n == 1) return A;
    
    matrix22 half = power(n/2);
    
    if (n % 2 == 0) return multiply(half, half);
    else return multiply(multiply(half, half), A);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    if (N == 1) cout << 3;
    else {
        matrix22 A_pow = power(N-1);
        
        long long an = (A_pow.first.first + A_pow.first.second) % MOD;
        long long bn = (A_pow.second.first + A_pow.second.second) % MOD;
        
        cout << ((2 * bn % MOD) + an) % MOD;
    }
    
    return 0;
}
