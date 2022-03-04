#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, bool> piib;

int n, m, t;
int s, g, h;
int a, b, d, x;
vector<pii> adj[2001];
vector<int> answer;
int dist[2001];
bool possible[2001];
priority_queue<piib, vector<piib>, greater<piib>> pq;

int INF = 987654321;

void init_testcase() {
    for (int i=1; i<=2000; i++) adj[i].clear();
    answer.clear();
    for (int i=1; i<=2000; i++) dist[i] = INF;
    memset(possible, 0, sizeof(possible));
}

void dijkstra(int start) {
    dist[start] = 0;
    pq.push({{0, start}, false});
    
    while (!pq.empty()) {
        piib curr = pq.top(); pq.pop();
        int curr_w = curr.first.first;
        int idx = curr.first.second;
        bool passGH = curr.second;  // G와 H를 잇는 간선을 사용했는지 여부
        
        if (curr_w > dist[idx]) continue;
        
        for (int i=0; i<adj[idx].size(); i++) {
            int next = adj[idx][i].first;
            int w = adj[idx][i].second;
            bool nextPassGH = (idx == g && next == h) || (idx == h && next == g) || passGH;
            
            if (dist[idx] + w < dist[next]) {
                dist[next] = dist[idx] + w;
                possible[next] = nextPassGH;
                pq.push({{dist[next], next}, nextPassGH});
            } else if (dist[idx] + w == dist[next]) {
                if (!possible[next] && nextPassGH) {
                    pq.push({{dist[next], next}, nextPassGH});
                }
                possible[next] = possible[next] || nextPassGH;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        init_testcase();
        
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        
        for (int i=0; i<m; i++) {
            cin >> a >> b >> d;
            
            adj[a].push_back({b, d});
            adj[b].push_back({a, d});
        }
        
        dijkstra(s);
        
        for (int i=0; i<t; i++) {
            cin >> x;
            
            if (possible[x] && dist[x] != INF) answer.push_back(x);
        }
        
        sort(answer.begin(), answer.end());
        
        for (int i=0; i<answer.size(); i++) {
            cout << answer[i] << " ";
        }
        
        cout << "\n";
    }
    
    return 0;
}
