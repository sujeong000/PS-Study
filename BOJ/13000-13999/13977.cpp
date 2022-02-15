#include <iostream>

using namespace std;

long long MOD = 1000000007;
long long N, K, M;
int factorial[4000001];

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

long long query(long long N, long long K) {
    long long A = factorial[N];
    long long B = factorial[N-K];
    long long C = factorial[K];
    
    return A * modularInverse(B * C % MOD) % MOD;
}

void calcFactorial() {
    factorial[0] = 1;
    
    long long x = 1;
    
    for(int i=1; i<=4000000; i++) {
        x *= i;
        x %= MOD;
        
        factorial[i] = x;
    }
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	calcFactorial();
	
    cin >> M;
    
    for(int i=0; i<M; i++) {
        cin >> N >> K;
        cout << query(N, K) << "\n";
    }
    
    return 0;
}

