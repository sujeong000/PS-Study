#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

int N, K;

void BFS() {
    vector<int> visit(200001, -1);
    vector<int> before(200001, -1);
    queue<int> q;
    
    visit[N] = 0;
    q.push(N);
    
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        
        if (curr == K) {
            vector<int> route;
            
            while (curr != -1) {
                route.push_back(curr);
                curr = before[curr];
            }
            
            reverse(route.begin(), route.end());
            
            cout << route.size()-1 << "\n";
            for (auto node: route) cout << node << " ";
            
            return;
        }
        
        int nexts[] = {curr-1, curr+1, curr*2};
        for (auto next: nexts) {
            if (next < 0 || next > 200000) continue;
            if (visit[next] != -1) continue;
            
            visit[next] = visit[curr] + 1;
            before[next] = curr;
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

