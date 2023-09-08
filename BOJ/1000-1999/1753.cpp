/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int MAX_V = 2e5+1;
const int MAX_E = 3e5+1;
const int INF = 987654321;

int V, E, K;
vector<pii> adjs[MAX_V];

vector<int> dijkstra() {
    vector<int> dist(V+1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    dist[K] = 0;
    pq.push({0, K});
    
    while (!pq.empty()) {
        int currDist = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        
        if (currDist > dist[curr]) continue;
        
        for (auto adj: adjs[curr]) {
            int next = adj.first;
            int weight = adj.second;
            int nextDist = currDist + weight;
            
            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
    
    return dist;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> V >> E >> K;
    while (E--) {
        int u, v, w;
        cin >> u >> v >> w;
        adjs[u].push_back({v, w});
    }
    
    vector<int> dist = dijkstra();
    for (int i=1; i<=V; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
    
    return 0;
}
