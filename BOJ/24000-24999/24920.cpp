#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;

const long long ORDER = 9999999999;
ll T, D, N, U;
priority_queue<pll, vector<pll>, greater<pll>> pq;
vector<plll> query;

ll solution() {
    sort(query.begin(), query.end());
    
    ll ret = 0;
    
    for (int i=0; i<query.size(); i++) {
        plll q = query[i];
        ll t = q.first;
        
        while (!pq.empty() && pq.top().first <= t) pq.pop();
        
        if (q.second.first == ORDER) {
            ll amount = U;
            
            while (amount > 0) {
                if (pq.empty()) return ret;
                
                pll curr = pq.top(); pq.pop();
                ll remove_amount = min(curr.second, amount);
                curr.second -= remove_amount;
                amount -= remove_amount;
                if (curr.second != 0) pq.push(curr);
            }
            
            ret++;
        }
        else pq.push(q.second);
    }
    
    return ret;
}

void init_testcase() {
    while (!pq.empty()) pq.pop();
    query.clear();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    
    for (int t=1; t<=T; t++) {
        init_testcase();
        
        cin >> D >> N >> U;
        
        ll m, l, e;
        for (int i=0; i<D; i++) {
            cin >> m >> l >> e;
            query.push_back({m, {m+e, l}});
        }
        
        ll o;
        for (int i=0; i<N; i++) {
            cin >> o;
            query.push_back({o, {ORDER, ORDER}});
        }
        
        ll ans = solution();
        
        cout << "Case #" << t << ": ";
        cout << ans;
        cout << "\n";
    }

    return 0;
}
