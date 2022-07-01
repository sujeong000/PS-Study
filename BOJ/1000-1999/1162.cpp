#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
const ll INF = LLONG_MAX;

int N, M, K;
vector<pll> adjs[10001];

ll dijkstra() {
    // dist[idx][k]: k개의 포장을 했을 때, 1번노드에서 idx번 노드까지 최소 시간
    vector<vector<ll>> dist(10001, vector<ll>(21, INF));
    priority_queue<plll, vector<plll>, greater<plll>> pq; 
    
    dist[1][0] = 0;
    pq.push({0, {1, 0}});
    
    while (!pq.empty()) {
        ll d = pq.top().first;
        ll curr = pq.top().second.first;
        ll k = pq.top().second.second;
        pq.pop();
        
        if (d > dist[curr][k]) continue;
        
        for (int i=0; i<adjs[curr].size(); i++) {
            ll next = adjs[curr][i].first;
            ll w = adjs[curr][i].second;
            
            // 포장 안하는 경우
            if (d+w < dist[next][k]) {
                dist[next][k] = d+w;
                pq.push({d+w, {next, k}});   
            }
            
            // 포장하는 경우
            if (k < K && d < dist[next][k+1]) {
                dist[next][k+1] = d;
                pq.push({d, {next, k+1}});
            }
        }
    }
    
    return *min_element(dist[N].begin(), dist[N].end());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> K;
    
    for (int i=0; i<M; i++) {
        ll s, e, w;
        cin >> s >> e >> w;
        
        adjs[s].push_back({e, w});
        adjs[e].push_back({s, w});
    }
    
    cout << dijkstra();

    return 0;
}
