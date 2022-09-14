#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

bool checkPrime(int x) {
    for (ll i=2; i*i<=x; i++) {
        if (x % i == 0) return false;
    }
    
    return true;
}

vector<int> calcInterestingPrimes(int len) {
    if (len == 1) return {2, 3, 5, 7};
    
    vector<int> ret;
    vector<int> arr = calcInterestingPrimes(len-1);
    
    for (auto x: arr) {
        for (int i=0; i<=9; i++) {
            if (checkPrime(x*10+i)) {
                ret.push_back(x*10+i);
            }
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<int> ans = calcInterestingPrimes(N);
    for (auto x: ans) cout << x << "\n";
    
    return 0;
}
