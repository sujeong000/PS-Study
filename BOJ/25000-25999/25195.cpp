#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100001;

int N, M, S;
vector<int> adj[MAX];
bool fanclub[MAX];

bool DFS(int curr) {
    if (fanclub[curr]) return false;
    if (adj[curr].empty()) return !fanclub[curr];
    
    for (auto next : adj[curr]) {
        if (DFS(next)) return true;
    }
    
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    int u, v;
    for (int i=0; i<M; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    cin >> S;
    for (int i=0; i<S; i++) {
        cin >> u;
        fanclub[u] = true;
    }
    
    if (DFS(1)) cout << "yes";
    else cout << "Yes";

    return 0;
}
