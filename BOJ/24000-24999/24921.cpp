#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll INF = 999999999999999999;
ll T, N;
ll adj[1001][1001];
bool visit[1001];
queue<pll> q;

pll find_far(int from) {
    memset(visit, 0, sizeof(visit));
    
    pll far = {0, -1};
    visit[from] = true;
    q.push({from, 0});
    
    while (!q.empty()) {
        ll curr = q.front().first;
        ll cost = q.front().second;
        
        if (far.second < cost) far = q.front();
        q.pop();
        
        for (int next=1; next<=N; next++) {
            if (!adj[curr][next] || visit[next]) continue;
            visit[next] = true;
            q.push({next, cost+adj[curr][next]});
        }
    }
    
    return far;
}

ll solution() {
    ll ret = 0;
    
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            ret += adj[i][j];
        }
    }
    
    pll far = find_far(1);
    far = find_far(far.first);
    ll diameter = far.second;
    
    return ret - diameter;
}

void init_testcase() {
    memset(adj, 0, sizeof(adj));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    
    for (int t=1; t<=T; t++) {
        init_testcase();
        
        cin >> N;
        
        ll s, e, w;
        for (int i=0; i<N-1; i++) {
            cin >> s >> e >> w;
            adj[s][e] = w;
            adj[e][s] = w;
        }
        
        ll ans = solution();
        
        cout << "Case #" << t << ": ";
        cout << ans;
        cout << "\n";
    }

    return 0;
}
