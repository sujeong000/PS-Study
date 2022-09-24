#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
const int INF = 987654321;

bool dfs(int start, int curr, int cnt, const vector<vector<int>>& adjs, vector<bool>& visit) {
    visit[curr] = true;
    
    for (auto next: adjs[curr]) {
        if (!visit[next]) {
            if (dfs(start, next, cnt+1, adjs, visit)) return true;
        }
        else if (next == start && cnt >= 2) return true;
    }
    
    return false;
}

vector<int> bfs(int n, const vector<int>& starts, const vector<vector<int>>& adjs) {
    vector<int> dist(n+1, INF);
    queue<int> q;
    
    for (auto start: starts) {
        dist[start] = 0;
        q.push(start);
    }
    
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        
        for (auto next: adjs[curr]) {
            if (dist[curr] + 1 < dist[next]) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
    
    return dist;
}

vector<int> solution(int n, vector<vector<int>> adjs) {
    vector<int> answer;
    vector<int> cycleNodes(n+1);
    
    for (int i=1; i<=n; i++) {
        vector<bool> visit(n+1, false);
        if (dfs(i, i, 0, adjs, visit)) cycleNodes.push_back(i);
    }
    
    answer = bfs(n, cycleNodes, adjs);
    
    return answer;
}

int main()
{
    int n;
    cin >> n;
    
    vector<vector<int>> adjs(n+1, vector<int>());
    for (int i=0; i<n; i++) {
        int s, e; cin >> s >> e;
        adjs[s].push_back(e);
        adjs[e].push_back(s);
    }
    
    auto ans = solution(n, adjs);
    for (int i=1; i<=n; i++) cout << ans[i] << " ";

    return 0;
}
