#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

// 소인수분해
vector<int> calcDivisors(int N) {
    vector<int> divisors;
    int n = N;
    
    for (int i=2; i*i<=N; i++) {
        if (n % i == 0) divisors.push_back(i);
        while (n % i == 0) n /= i;
    }
    
    if (n > 1) divisors.push_back(n);
    
    return divisors;
}

int countCoprime(int N) {
    vector<int> divisors = calcDivisors(N);
    int coprimeCnt = N;
    
    for (auto d: divisors) {
        coprimeCnt /= d;
        coprimeCnt *= d-1;
    }
    
    return coprimeCnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    
    while (true) {
        int N; cin >> N;
        if (N == 0) break;
        
        cout << countCoprime(N) << "\n";
    }

    return 0;
}
