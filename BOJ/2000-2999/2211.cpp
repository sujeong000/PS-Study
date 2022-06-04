#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef pair<int, int> pii;
const int MAX = 1001, INF = 987654321;

int N, M, A, B, C;
vector<pii> adj[MAX];

set<pii> dijkstra() {
    set<pii> ret;
    vector<int> d(N+1, INF);
    vector<int> before(N+1);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    for (int i=0; i<=N; i++) before[i] = i;
    d[1] = 0;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        int currD = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        
        if (currD > d[curr]) continue;
        
        for (auto x: adj[curr]) {
            int next = x.first;
            int w = x.second;
            
            if (d[curr]+w < d[next]) {
                d[next] = d[curr]+w;
                before[next] = curr;
                pq.push({d[next], next});
            }
        }
    }

    for (int i=1; i<=N; i++) {
        int p = i;
        
        while (p != before[p]) {
            ret.insert({min(p, before[p]), max(p, before[p])});  
            p = before[p];
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        cin >> A >> B >> C;
        adj[A].push_back({B, C});
        adj[B].push_back({A, C});
    }
    
    set<pii> ans = dijkstra();
    
    cout << ans.size() << "\n";
    for (auto edge: ans) {
        cout << edge.first << " " << edge.second << "\n";
    }

    return 0;
}
