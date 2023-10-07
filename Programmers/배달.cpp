#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int INF = 987654321;
const int MAX = 50;

int n, k;
vector<pii> adjs[MAX+1];

int dijkstra() {
    int ret = 0;
    vector<int> dist(n+1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    // 시작점
    dist[1] = 0;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        int currDist = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();
        
        if (currDist > dist[currNode]) continue;
        
        for (auto adj: adjs[currNode]) {
            int nextDist = adj.first + currDist;
            int nextNode = adj.second;
            
            if (nextDist < dist[nextNode]) {
                dist[nextNode] = nextDist;
                pq.push({nextDist, nextNode});
            }
        }
    }
    
    for (int i=1; i<=n; i++) {
        if (dist[i] <= k) ret++;
    }
    
    return ret;
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    n = N;
    k = K;

    // 간선처리
    for (auto edge: road) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adjs[u].push_back({w, v});
        adjs[v].push_back({w, u});
    }
    
    answer = dijkstra();

    return answer;
}
