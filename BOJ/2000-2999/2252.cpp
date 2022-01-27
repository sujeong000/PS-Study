#include <iostream>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;

int N, M;
int indegree[32001];
vector<int> edges[32001];

void topologySort() {
    queue<int> q;
    
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) q.push(i);
    }
    
    while (!q.empty()) {
        int current = q.front(); q.pop();
        
        cout << current << " ";
        
        for (int i=0; i<edges[current].size(); i++) {
            int end = edges[current][i];
            indegree[end]--;
            if (indegree[end] == 0) q.push(end);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    int A, B;
    for (int i=0; i<M; i++) {
        cin >> A >> B;
        edges[A].push_back(B);
        indegree[B]++;
    }
    
    topologySort();

    return 0;
}
