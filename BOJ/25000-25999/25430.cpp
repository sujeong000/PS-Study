#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> Node;   // {d, {w, curr}}
const ll INF = 1e12+1;

int N, M, S, E;
vector<pll> adjs[50001];
map<int, ll> dist[50001];   // dist[N][w] = d

ll dijkstra() {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    ll ret = INF;
    
    dist[S][0] = 0;
    pq.push({0, {0, S}});
    
    while (!pq.empty()) {
        ll d = pq.top().first;
        ll w = pq.top().second.first;
        ll curr = pq.top().second.second;
        pq.pop();
        
        if (curr == E) ret = min(ret, d);
        if (d > dist[curr][w]) continue;
        
        for (auto adj: adjs[curr]) {
            ll next = adj.first;
            ll nw = adj.second;
            
            if (nw <= w) continue;
            if (d+nw > dist[next][nw]) continue;
            
            dist[next][nw] = d+nw;
            pq.push({d+nw, {nw, next}});
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        
        adjs[s].push_back({e, w});
        adjs[e].push_back({s, w});
        
        dist[s][w] = INF;
        dist[e][w] = INF;
    }
    cin >> S >> E;
    
    ll ans = dijkstra();
    
    if (ans == INF) cout << "DIGESTA";
    else cout << ans;
    
    return 0;
}
