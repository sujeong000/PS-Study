#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int N;
pll f[100001];

ll calcMaxSum() {
    ll ret = 0;
    
    sort(f+1, f+1+N);
    
    for (int i=1; i<=N; i++) {
        ret += f[i].first*i + f[i].second;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    for (int i=1; i<=N; i++) {
        ll a, b;
        cin >> a >> b;
        f[i] = {a, b};
    }
    
    cout << calcMaxSum();
    
    return 0;
}
