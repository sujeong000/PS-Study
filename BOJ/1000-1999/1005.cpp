#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int N, K;
int indegree[1001], buildCost[1001], totalCost[1001];
int edges[1001][1001];

int topologySort(int target) {
    for (int s = 1; s <= N; s++) {
        for (int e = 1; e <= N; e++) {
            if (edges[s][e] == 1) indegree[e]++;
        }
    }
    
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        totalCost[i] = buildCost[i];
        if (indegree[i] == 0) q.push(i);
    }
    
    while (!q.empty()) {
        int current = q.front(); q.pop();
        
        if (current == target) return totalCost[current];
        
        for (int end = 1; end <= N; end++) {
            if (edges[current][end] == 1) {
                totalCost[end] = max(totalCost[end], totalCost[current] + buildCost[end]);
                indegree[end]--;
                if (indegree[end] == 0) q.push(end);
            }
        }
    }
    
    return 0;
}

void initTestcase() {
    memset(indegree, 0, 1001 * sizeof(int));
    memset(totalCost, 0, 1001 * sizeof(int));
    memset(edges, 0, 1001 * 1001 * sizeof(int));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T) {
        initTestcase();
        
        cin >> N >> K;
        
        for (int i=1; i<=N; i++) {
            int x;
            cin >> x;
            buildCost[i] = x;
        }
        
        for (int i=0; i<K; i++) {
            int s, e;
            cin >> s >> e;
            edges[s][e] = 1;
        }
        
        int W;
        cin >> W;
        cout << topologySort(W) << "\n";
        
        T--;
    }

    return 0;
}
