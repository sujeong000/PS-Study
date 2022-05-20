#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MAX = 100001;

int N, S, C, H;
vector<int> adj[MAX], child[MAX];
int parent[MAX], depth[MAX];
bool visit[MAX];

void DFS(int curr) {
    visit[curr] = true;
    
    for (auto next: adj[curr]) {
        if (visit[next]) continue;
        
        parent[next] = curr;
        depth[next] = depth[curr] + 1;
        child[curr].push_back(next);
        DFS(next);
    }
}

int LCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    while (depth[u] > depth[v]) u = parent[u];
    
    while (u != v) {
        u = parent[u];
        v = parent[v];
    }
    
    return u;
}

int dist(int u, int v) {
    if (u == v) return 0;
    
    for (auto next: child[u]) {
        int d = dist(next, v);
        if (d != -1) return d + 1;
    }
    
    return -1;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    cin >> S >> C >> H;
    
    int u, v;
    for (int i=0; i<N-1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // C를 루트로 하는 트리로 만들기
    DFS(C);
    
    int lca = LCA(S, H);
    ll X = dist(lca, S);        // S와 LCA 사이에 존재하는 노드들
    ll Y = dist(C, lca) + 1;    // LCA와 C 사이에 존재하는 노드들
    ll Z = dist(lca, H);        // H와 LCA 사이에 존재하는 노드들
    
    // 방문 순서는 X -> Y -> Y -> Z
    // 순서쌍 개수 = (X,X) + (Y,Y) + (Z,Z) + (X,Y) + (X,Z) + (Y,Z)
    ll ans = X*(X-1)/2 + Y*(Y-1) + Z*(Z-1)/2 + X*Y + X*Z + Y*Z;
    
    cout << ans;

    return 0;
}
