#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
const int INF = 987654321;

int N, M;
vector<pii> adjs[1001];
int before[1001];

bool isSameEdge(pii lhs, pii rhs) {
    if (lhs.first == rhs.first && lhs.second == rhs.second) return true;
    if (lhs.first == rhs.second && lhs.second == rhs.first) return true;
    return false;
}

int dijkstra(int from, int to, pii exceptedEdge) {
    vector<int> dist(N+1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    dist[from] = 0;
    pq.push({0, from});
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        
        if (d > dist[curr]) continue;
        
        for (auto adj: adjs[curr]) {
            int w = adj.first;
            int next = adj.second;
            
            if (isSameEdge({curr, next}, exceptedEdge)) continue;
            
            if (d + w < dist[next]) {
                dist[next] = d + w;
                pq.push({dist[next], next});
                if (exceptedEdge == make_pair(-1, -1)) before[next] = curr;
            }
        }
    }
    
    return dist[to];
}

int solution() {
    int minDist = dijkstra(1, N, {-1, -1});
    int maxDist = 0;
    
    // 최단경로에 포함된 간선 하나씩 지워보기
    for (int curr = N; curr != 0; curr = before[curr]) {
        maxDist = max(maxDist, dijkstra(1, N, {curr, before[curr]}));
    }
    
    if (maxDist == INF) return -1;
    else return maxDist - minDist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    for (int i=0; i<M; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        adjs[a].push_back({t, b});
        adjs[b].push_back({t, a});
    }
    
    cout << solution();

    return 0;
}
