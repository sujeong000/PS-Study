#include <iostream>
#include <string.h>

using namespace std;

const int INF = 987654321;
const int MAX_V = 2005;
int N, M, K, SRC, P, SINK;
int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];
int parent[MAX_V];

void DFS(int here) {
    if (parent[SINK] != -1) return;
    
    for (int there = 0; there <= SINK; there++) {
        if (capacity[here][there] - flow[here][there] > 0 && parent[there] == -1) {
            parent[there] = here;
            DFS(there);
        }
    }
}

int Ford_Fulkerson() {
    int total_flow = 0;
    
    while (true) {
        memset(parent, -1, sizeof(parent));
        
        parent[SRC] = SRC;
        DFS(SRC);
        
        if (parent[SINK] == -1) break;
        
        int amount = INF;
        
        for (int p = SINK; p != SRC; p = parent[p]) {
            amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
        }
        
        for (int p = SINK; p != SRC; p = parent[p]) {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        
        total_flow += amount;
    }
    
    return total_flow;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> K;
    
    SRC = N + M + 1;
    SINK = N + M + 2;
    
    capacity[SRC][P] = K;
    
    int cnt, work;
    
    for (int person=1; person<=N; person++) {
        cin >> cnt;
        
        for (int i=0; i<cnt; i++) {
            cin >> work;
            work += N;
            capacity[person][work] = 1;
        }
        
        capacity[P][person] = K;
        capacity[SRC][person] = 1;
    }
    
    for (int work=N+1; work<=N+M; work++) {
        capacity[work][SINK] = 1;
    }
    
    cout << Ford_Fulkerson();

    return 0;
}
