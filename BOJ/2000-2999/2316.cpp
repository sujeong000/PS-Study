#include <iostream>
#include <string.h>

using namespace std;

const int INF = 987654321;
const int MAX_V = 801;
int N, P;
int SRC = 401, SINK = 2;
int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];
int parent[MAX_V];

void DFS(int here) {
    if (parent[SINK] != -1) return;
    
    for (int there=1; there<=MAX_V; there++) {
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
        
        for (int p = SINK; p != SRC; p = parent[p]) {
            flow[parent[p]][p] += 1;
            flow[p][parent[p]] -= 1;
        }
        
        total_flow += 1;
    }
    
    return total_flow;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> P;
    
    for (int i=1; i<=N; i++) {
        capacity[i][i+400] = 1; // 정점 분할, 각 정점을 한번씩만 방문하도록
    }
    
    int s, e;
    
    for (int i=0; i<P; i++) {
        cin >> s >> e;
        capacity[s+400][e] = INF;
        capacity[e+400][s] = INF;
    }
    
    // 2->1로 돌아올 수 있다 == 1->2로 갈 수도 있다는 뜻
    // 1->2로 가는 유량과 같다.
    cout << Ford_Fulkerson();

    return 0;
}
