#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N, M;
vector<int> indegree(101);
vector<pii> adjs[101];

vector<int> topologySort() {
    vector<vector<int>> parts(N+1, vector<int>(N+1, 0));
    queue<int> q;
    
    for (int i=1; i<=N; i++) {
        if (indegree[i] == 0) {
            parts[i][i] = 1;
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        
        for (auto adj: adjs[curr]) {
            int next = adj.first;
            int w = adj.second;
            
            for (int i=1; i<=N; i++) {
                parts[next][i] += parts[curr][i] * w;
            }
            
            if (--indegree[next] == 0) {
                q.push(next);
            }
        }
    }
    
    return parts[N];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int x, y, k;
        cin >> x >> y >> k;
        
        adjs[y].push_back({x, k});
        indegree[x]++;
    }
    
    auto ans = topologySort();
    
    for (int i=1; i<=N; i++) {
        if (ans[i] == 0) continue;
        cout << i << " " << ans[i] << "\n";
    }

    return 0;
}
