#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

typedef long long ll;

int N, M;
int arr[501];
bool adjs[501][501], visit[501], finished[501];

bool DFS(int curr) {
    visit[curr] = true;
    
    for (int next=1; next<=N; next++) {
        if (!adjs[curr][next]) continue;
        
        if (!visit[next]) {
            if (DFS(next)) return true;
        }
        else if (!finished[next]) {
            return true;
        }
    }
    
    finished[curr] = true;
    return false;
}

bool checkCycle() {
    memset(visit, 0, sizeof(visit));
    memset(finished, 0, sizeof(finished));
    
    for (int i=1; i<=N; i++) {
        if (!visit[i]) {
            if (DFS(i)) return true;
        }
    }
    
    return false;
}

vector<int> topologicalSort() {
    vector<int> indegree(N+1, 0);
    vector<int> ret;
    queue<int> q;
    
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (adjs[i][j]) indegree[j]++;
        }
    }
    
    for (int i=1; i<=N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        ret.push_back(curr);
        
        int cnt = 0;
        for (int next=1; next<=N; next++) {
            if (adjs[curr][next]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                    cnt++;
                }
            }
        }
        
        if (cnt > 1) return {};
    }
    
    return ret;
}

void initTestcase() {
    memset(adjs, 0, sizeof(adjs));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while (T--) {
        initTestcase();
        
        cin >> N;
        for (int i=0; i<N; i++) cin >> arr[i];
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                adjs[arr[i]][arr[j]] = true;
            }
        }
        
        cin >> M;
        for (int i=0; i<M; i++) {
            int x, y; cin >> x >> y;
            adjs[x][y] = !adjs[x][y];
            adjs[y][x] = !adjs[y][x];
        }
        
        if (checkCycle()) {
            cout << "IMPOSSIBLE";
        }
        else {
            vector<int> ans = topologicalSort();
            if (ans.empty()) cout << "?";
            else for (auto x : ans) cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}
