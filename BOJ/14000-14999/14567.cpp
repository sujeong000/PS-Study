#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

int N, M;
int indegree[1001], cost[1001], totalCost[1001];
vector<int> edges[1001];

void topologySort() {
    queue<int> q;
    
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            totalCost[i] = cost[i];
        }
    }
    
    while (!q.empty()) {
        int current = q.front(); q.pop();
        
        for (int i = 0; i < edges[current].size(); i++) {
            int end = edges[current][i];
            totalCost[end] = max(totalCost[end], totalCost[current] + cost[end]);
            indegree[end]--;
            if (indegree[end] == 0) q.push(end);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int s, e;
    
    cin >> N >> M;
    
    for (int i=1; i<=N; i++) {
        cost[i] = 1;
    }

    for (int i=0; i<M; i++) {
        cin >> s >> e;
        
        edges[s].push_back(e);
        indegree[e]++;
    }
    
    topologySort();
    
    for (int i=1; i<=N; i++) {
        cout << totalCost[i] << " ";
    }

    return 0;
}
