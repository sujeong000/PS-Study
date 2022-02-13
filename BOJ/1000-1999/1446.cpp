#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, D;
int dist[10001];
vector<pair<int, int>> adj[10001];

int dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    for (int i=1; i<=D; i++) dist[i] = 987654321;
    dist[0] = 0;
    pq.push({0, 0});
    
    while (!pq.empty()) {
        pair<int, int> current = pq.top(); pq.pop();
        int d = current.first;
        int n = current.second;
        
        if (dist[n] < d) continue;
        
        for (int i=0; i<adj[n].size(); i++) {
            int next = adj[n][i].first;
            int weight = adj[n][i].second;
            
            if (d + weight < dist[next]) {
                dist[next] = d + weight;
                pq.push({dist[next], next});
            }
        }
    }
    
    return dist[D];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> D;
    
    int s, e, w;
    
    for (int i=0; i<N; i++) {
        cin >> s >> e >> w;
        adj[s].push_back({e, w});
    }
    
    for (int i=0; i<D; i++) {
        adj[i].push_back({i+1, 1});
    }
    
    cout << dijkstra();

    return 0;
}
