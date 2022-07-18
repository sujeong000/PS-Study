#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int N;
vector<int> divisors;

int countOne(int mask) {
    int ret = 0;
    
    while (mask > 0) {
        ret += mask % 2;
        mask /= 2;
    }
    
    return ret;
}

int mul(int mask) {
    ll ret = 1;
    
    for (int i=0; i<divisors.size(); i++) {
        if ((mask & (1 << i)) != 0) {
            ret *= divisors[i];
            if (ret > N) return N;
        }
    }
    
    return ret;
}

void calcDivisors() {
    int n = N;
    
    for (int i=2; i*i<=N; i++) {
        if (n % i == 0) divisors.push_back(i);
        while (n % i == 0) n /= i;
    }
    
    if (n > 1) divisors.push_back(n);
}

int countCoprime() {
    calcDivisors();
    
    int M = divisors.size();
    int cnt = 0;
    
    for (int i=0; i<(1 << M); i++) {
        if (countOne(i) % 2) cnt -= (N-1)/mul(i);
        else cnt += (N-1)/mul(i);
    }
    
    return cnt;
}

void initTestcase() {
    divisors.clear();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    
    while (true) {
        initTestcase();
        
        cin >> N;
        if (N == 0) break;
        
        cout << countCoprime() << "\n";
    }

    return 0;
}
