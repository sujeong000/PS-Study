#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<bool> is_prime(1000001, true);
vector<int> primes;

void calcPrimes() {
    for (int i=2; i<=1e6; i++) {
        if (!is_prime[i]) continue;
        
        int temp = i*2;
        while (temp <= 1e6) {
            is_prime[temp] = false;
            temp += i;
        }
    }
    
    for (int i=2; i<=1e6; i++) {
        if (is_prime[i]) primes.push_back(i);
    }
}

string solution(int n) {
    for (auto prime: primes) {
        if (prime >= n) return "Goldbach's conjecture is wrong.";
        
        if (is_prime[n-prime]) {
            return to_string(n) + " = " + to_string(prime) + " + " + to_string(n-prime);
        }    
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    calcPrimes();
    
    while (true) {
        int n; cin >> n;
        if (n == 0) break;
        cout << solution(n) << "\n";
    }

    return 0;
}
