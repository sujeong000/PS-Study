#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <map>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;

int MOD = 1000000007;

int N, M;
bool visit[200001];
vector<int> adj[200001];
queue<int> q;

ll BFS(int s) {
    q.push(s);
    visit[s] = true;
    
    ll cnt = 0;
    
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        
        cnt++;
        
        for(int i=0; i<adj[curr].size(); i++) {
            int next = adj[curr][i];
            
            if (visit[next]) continue;
            
            q.push(next);
            visit[next] = true;
        }
    }
    
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    
    int s, e;
    
    for(int i=0; i<M; i++) {
        cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    
    ll result = 1;
    
    for(int i=1; i<=N; i++) {
        if (!visit[i]) {
            ll cnt = BFS(i);
            result *= cnt;
            result %= MOD;
        }
    }
    
    cout << result;

    return 0;
}
