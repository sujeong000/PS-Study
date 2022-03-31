#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

ll N, P, Q;
map<ll, ll> cache;

ll A(ll n) {
    if (n == 0) return 1;
    
    if (cache.find(n) != cache.end()) return cache[n];
    
    ll ret = A(n/P) + A(n/Q);
    cache[n] = ret;
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> P >> Q;
    cout << A(N);

    return 0;
}
