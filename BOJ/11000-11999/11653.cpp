#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<ll> factors;

void factorize(ll N) {
    ll i = 2;
    ll original_N = N;
    
    while (i <= N && i * i <= original_N) {
        if (N % i == 0) {
            factors.push_back(i);
            N /= i;
        } else {
            if (i == 2) i++;
            else i += 2;
        }
    }
    
    if (N > 1) factors.push_back(N);
    
    sort(factors.begin(), factors.end());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll N;
    cin >> N;
    
    factorize(N);
    
    for (int i=0; i<factors.size(); i++) {
        cout << factors[i] << "\n";
    }
    
    return 0;
}
