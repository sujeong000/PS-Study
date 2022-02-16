#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int K, V, E;
vector<int> adj[20001];
bool visit[20001];
int mark[20001];

bool BFS(int start) {
    queue<int> q;
    
    q.push(start);
    visit[start] = true;
    mark[start] = 1;
    
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        
        for (int i=0; i<adj[curr].size(); i++) {
            int adjacent = adj[curr][i];
            
            if (mark[adjacent] == mark[curr]) return false;
            
            mark[adjacent] = -mark[curr];
            if (!visit[adjacent]) {
                q.push(adjacent);
                visit[adjacent] = true;
            }
        }
    }
    
    return true;
}

bool solution() {
    for(int i=1; i<=V; i++) {
        if (visit[i]) continue;
        if (!BFS(i)) return false;
    }
    
    return true;
}

void init_testcase() {
    for(int i=0; i<20001; i++) {
        adj[i].clear();
    }
    
    memset(visit, 0, sizeof(visit));
    memset(mark, 0, sizeof(mark));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> K;
    
    while (K--) {
        init_testcase();
        
        cin >> V >> E;
        
        int s, e;
        
        for (int i=0; i<E; i++) {
            cin >> s >> e;
            adj[s].push_back(e);
            adj[e].push_back(s);
        }
        
        if (solution()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
