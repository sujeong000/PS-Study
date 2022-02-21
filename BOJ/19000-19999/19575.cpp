#include <iostream>

using namespace std;

long long MOD = 1000000007;
long long N, x;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> x;
    
    long long A, B;
    long long result = 0;
    
    for(int i = 0; i < N+1; i++) {
        cin >> A >> B;
        result = result * x % MOD;
        result = result + A % MOD;
    }
    
    cout << result;

    return 0;
}
