#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int indegree[32001];
vector<int> adjacents[32001];
priority_queue<int, vector<int>, greater<int>> pq;

void topology_sort() {
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }
    
    while (!pq.empty()) {
        int curr = pq.top(); pq.pop();
        
        cout << curr << " ";
        
        for (int i = 0; i < adjacents[curr].size(); i++) {
            int adj = adjacents[curr][i];
            indegree[adj]--;
            if (indegree[adj] == 0) {
                pq.push(adj);
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    
    int s, e;
    
    for (int i = 0; i < M; i++) {
        cin >> s >> e;
        adjacents[s].push_back(e);
        indegree[e]++;
    }
    
    topology_sort();

    return 0;
}
