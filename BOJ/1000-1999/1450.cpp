#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int N, C;
vector<int> items(30);
vector<int> lCombi, rCombi;

void makeCombi(vector<int>& v, int idx, int x, int end) {
    if (x > C) return;
    if (idx == end) {
        v.push_back(x);
        return;
    }

    makeCombi(v, idx+1, x+items[idx], end);
    makeCombi(v, idx+1, x, end);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> C;
    for (int i=0; i<N; i++) cin >> items[i];

    makeCombi(lCombi, 0, 0, N/2);
    makeCombi(rCombi, N/2, 0, N);
    
    sort(rCombi.begin(), rCombi.end());
    
    ll ans = 0;
    for (auto x: lCombi) {
        ans += upper_bound(rCombi.begin(), rCombi.end(), C-x) - rCombi.begin();
    }
    
    cout << ans;

    return 0;
}
