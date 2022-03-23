#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll N;
vector<ll> tidy;

void calc_tidy(ll x) {
    tidy.push_back(x);
    
    if (x > 100000000000000000) return;
    
    for (int i=x%10; i<=9; i++) {
        calc_tidy(x*10+i);
    }
}

int upper_bound(ll x) {
    int lo = 0, hi = tidy.size();
    
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (tidy[mid] <= x) lo = mid + 1;
        else hi = mid;
    }
    
    return lo;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int i=1; i<=9; i++) calc_tidy(i);
    sort(tidy.begin(), tidy.end());
    
    int T;
    cin >> T;
    
    for (int t=1; t<=T; t++) {
        cin >> N;
        
        int ub = upper_bound(N);
        ll ans = tidy[ub-1];
        
        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}
