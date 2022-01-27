#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

int N, maxTotalCost;
int indegree[10001], cost[10001], totalCost[10001];
vector<int> edges[10001];

int topologySort() {
    queue<int> q;
    
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            totalCost[i] = cost[i];
            maxTotalCost = max(maxTotalCost, totalCost[i]);
        }
    }
    
    while (!q.empty()) {
        int current = q.front(); q.pop();
        
        maxTotalCost = max(maxTotalCost, totalCost[current]);
        
        for (int i = 0; i < edges[current].size(); i++) {
            int end = edges[current][i];
            totalCost[end] = max(totalCost[end], totalCost[current] + cost[end]);
            indegree[end]--;
            if (indegree[end] == 0) q.push(end);
        }
    }
    
    return maxTotalCost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int c, edgeCount, end; 
    
    cin >> N;

    for (int i=1; i<=N; i++) {
        cin >> c;
        cost[i] = c;
        
        cin >> edgeCount;
        for(int j=0; j<edgeCount; j++) {
            cin >> end;
            edges[i].push_back(end);
            indegree[end]++;
        }
    }
    
    cout << topologySort();

    return 0;
}
