#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

int N;
int indegree[501], cost[501], totalCost[501];
vector<int> edges[501];

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
    
    int c, prev; 
    
    cin >> N;

    for (int i=1; i<=N; i++) {
        cin >> c;
        cost[i] = c;
        
        while (1) {
            cin >> prev;
            
            if (prev == -1) break;
            
            edges[prev].push_back(i);
            indegree[i]++;
        }
    }
    
    topologySort();
    
    for (int i=1; i<=N; i++) {
        cout << totalCost[i] << "\n";
    }

    return 0;
}
