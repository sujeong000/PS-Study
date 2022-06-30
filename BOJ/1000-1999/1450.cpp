#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int N, C;
int items[30];
map<int, int> lMap, rMap;
vector<int> lItems;
vector<ll> psum;

void makeMap(map<int, int>& mp, int idx, int x, int end) {
    if (x > C) return;
    if (idx == end) {
        mp[x]++;
        return;
    }

    makeMap(mp, idx+1, x+items[idx], end);
    makeMap(mp, idx+1, x, end);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> C;
    for (int i=0; i<N; i++) cin >> items[i];

    makeMap(lMap, 0, 0, N/2);
    makeMap(rMap, N/2, 0, N);
    
    int idx = 0;
    for (auto iter=lMap.begin(); iter != lMap.end(); iter++) {
        lItems.push_back(iter->first);
        if (idx == 0) psum.push_back(iter->second);
        else psum.push_back(psum.back() + iter->second);
        idx++;
    }
    
    ll ans = 0;
    for (auto iter=rMap.begin(); iter != rMap.end(); iter++) {
        int ub = upper_bound(lItems.begin(), lItems.end(), C - iter->first) - lItems.begin();
        ans += psum[ub-1] * iter->second;
    }
    
    cout << ans;

    return 0;
}
