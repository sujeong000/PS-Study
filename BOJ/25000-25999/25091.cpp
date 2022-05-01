#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int MAX = 100001, ABYSS = -1;
int T, N;
int adj[MAX], fun[MAX], indegree[MAX];
bool visit[MAX];
priority_queue<pii, vector<pii>, greater<pii>> pq;

void init_testcase() {
    memset(indegree, 0, sizeof(indegree));
    memset(visit, 0, sizeof(visit));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    for (int t=1; t<=T; t++) {
        init_testcase();
        
        cin >> N;
        for (int i=0; i<N; i++) cin >> fun[i];
        for (int i=0; i<N; i++) {
            cin >> adj[i];
            adj[i]--;
            if (adj[i] != ABYSS) indegree[adj[i]]++;
        }
        
        for (int i=0; i<N; i++) {
            if (indegree[i] == 0) {
                pq.push({fun[i], i});
                visit[i] = true;
            }
        }
        
        ll ans = 0;
        while (!pq.empty()) {
            int max_val = pq.top().first;
            int curr = pq.top().second;
            int next = adj[curr];
            pq.pop();
        
            if (next == ABYSS || visit[next]) {
                ans += max_val;
                continue;
            }
            
            max_val = max(max_val, fun[next]);
            pq.push({max_val, next});
            visit[next] = true;
        }
        
        cout << "Case #" << t << ": ";
        cout << ans;
        cout << "\n";
    }

    return 0;
}
