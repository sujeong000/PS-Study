#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

int N, K;

void BFS() {
    map<int, pii> visit;    // visit[x] = {최단거리, 이전노드}
    queue<int> q;
    
    visit[N] = {0, N};
    q.push(N);
    
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        
        if (curr == K) {
            vector<int> route;
            
            while (curr != visit[curr].second) {
                route.push_back(curr);
                curr = visit[curr].second;
            }
            route.push_back(N);
            
            reverse(route.begin(), route.end());
            
            cout << route.size()-1 << "\n";
            for (auto node: route) cout << node << " ";
            
            return;
        }
        
        int nexts[] = {curr-1, curr+1, curr*2};
        for (auto next: nexts) {
            if (next < 0) continue;
            if (next > 200000) continue;
            if (visit.find(next) != visit.end()) continue;
            
            visit[next] = {visit[curr].first+1, curr};
            q.push(next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    
    BFS();
    
    return 0;
}

