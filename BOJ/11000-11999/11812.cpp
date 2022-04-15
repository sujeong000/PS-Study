#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

ll N, K, Q, x, y;

int dist(ll u, ll v) {
    int ret = 0;
    
    // LCA까지 거슬러 올라가기
    while (u != v) {
        if (u > v) u = (u-1)/K;
        else v = (v-1)/K;
        ret++;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K >> Q;
    for (int i=0; i<Q; i++) {
        cin >> x >> y;
        x--; y--;
        
        if (K == 1) cout << max(x, y) - min(x, y) << "\n";
        else cout << dist(x, y) << "\n";
    }
    
    return 0;
}
