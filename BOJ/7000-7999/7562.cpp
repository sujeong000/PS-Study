#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

typedef pair<int, int> pii;
const int INF = 987654321;

int N;
pii s, e;

int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int BFS(pii s, pii e) {
    queue<pii> q;
    vector<vector<int>> dist(N, vector<int>(N, INF));
    
    dist[s.first][s.second] = 0;
    q.push(s);
    
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        if (make_pair(r, c) == e) return dist[r][c];
        
        for (int i=0; i<8; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if (dist[nr][nc] != INF) continue;
            
            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    
    while (T--) {
        cin >> N;
        cin >> s.first >> s.second;
        cin >> e.first >> e.second;
        
        cout << BFS(s, e) << "\n";
    }
    
    return 0;
}
