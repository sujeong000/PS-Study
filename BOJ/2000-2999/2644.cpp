#include <iostream>
#include <vector>

using namespace std;

int N, M, A, B;
vector<int> adj[101];
int depth[101];
bool visit[101];

void DFS(int curr, int d) {
    visit[curr] = true;
    depth[curr] = d;
    
    for (int next : adj[curr]) {
        if (!visit[next]) DFS(next, d+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    cin >> A >> B;
    cin >> M;
    
    int x, y;
    for (int i=0; i<M; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    DFS(A, 1);
    
    cout << depth[B] - 1;

    return 0;
}
