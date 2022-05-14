#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX = 200005;

int N, M, S;
int query[MAX], parent[MAX], sz[MAX], temp[MAX];
vector<int> adj[MAX];
bool used[MAX], result[MAX];
set<int> unconnect;

int find(int x) {
    if (parent[x] == x) return x;
    
    return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    a = find(a), b = find(b);
    
    if (a == b) return;
    
    if (sz[a] > sz[b]) swap(a, b);
    sz[b] += sz[a];
    parent[a] = b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int i=0; i<MAX; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
    
    cin >> N >> M;
    
    int s, e;
    for (int i=0; i<M; i++) {
        cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    
    for (int i=0; i<N; i++) cin >> query[i];
    S = query[N-1];
    
    for (int i=N-1; i>=0; i--) {
        int x = query[i];
        
        used[x] = true;
        unconnect.insert(x);
        
        for (auto y : adj[x]) {
            if (!used[y]) continue;
            merge(x, y);
        }
        
        int cnt = 0;
        for (auto y : unconnect) temp[cnt++] = y;
        for (int i=0; i<cnt; i++) {
            int y = temp[i];
            if (find(y) == find(S)) unconnect.erase(y);
        }
        
        result[i] = unconnect.empty();
    }
    
    for (int i=0; i<=N; i++) {
        if (result[i]) cout << "CONNECT\n";
        else cout << "DISCONNECT\n";
    }

    return 0;
}
