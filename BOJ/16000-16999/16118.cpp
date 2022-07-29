#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;
typedef pair<ll, pii> plii;
const ll INF = 987654321;
const int EVEN = 0, ODD = 1;

int N, M;
vector<pii> adjs[4001];

vector<ll> wolfDijkstra(int from) {
    vector<ll> ret(N+1);
    vector<vector<ll>> dist(2, vector<ll>(N+1, INF));
    priority_queue<plii, vector<plii>, greater<plii>> pq;
    
    dist[EVEN][from] = 0;
    pq.push({0, {EVEN, from}});
    
    while (!pq.empty()) {
        ll d = pq.top().first;
        int t = pq.top().second.first;
        int newT = 1 - t;
        int curr = pq.top().second.second;
        pq.pop();
        
        if (d > dist[t][curr]) continue;
        
        for (auto adj: adjs[curr]) {
            int next = adj.first;
            int c = adj.second;
            ll newD = (newT == ODD) ? d+c : d+c*4;
            
            if (newD < dist[newT][next]) {
                dist[newT][next] = newD;
                pq.push({dist[newT][next], {newT, next}});
            }
        }
    }
    
    for (int i=1; i<=N; i++) {
        ret[i] = min(dist[ODD][i], dist[EVEN][i]);
    }
    
    return ret;
}

vector<ll> foxDijkstra(int from) {
    vector<ll> dist(N+1, INF);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    
    dist[from] = 0;
    pq.push({0, from});
    
    while (!pq.empty()) {
        ll d = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        
        if (d > dist[curr]) continue;
        
        for (auto adj: adjs[curr]) {
            int next = adj.first;
            int c = adj.second;
            ll newD = d + c;
            
            if (newD < dist[next]) {
                dist[next] = newD;
                pq.push({dist[next], next});
            }
        }
    }
    
    for (int i=0; i<=N; i++) {
        dist[i] *= 2;
    }
    
    return dist;
}

int solution() {
    vector<ll> foxDist = foxDijkstra(1);
    vector<ll> wolfDist = wolfDijkstra(1);
    int cnt = 0;
    
    for (int i=1; i<=N; i++) {
        if (foxDist[i] < wolfDist[i]) cnt++;
    }
    
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        adjs[s].push_back({e, c});
        adjs[e].push_back({s, c});
    }
    
    cout << solution();

    return 0;
}
