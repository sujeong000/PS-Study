#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int N, M;
vector<pii> rooms[100][100];

int simulate() {
    int ret = 0;
    queue<pii> q;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<vector<bool>> light_on(N, vector<bool>(N, false));
    
    q.push({0, 0});
    visited[0][0] = true;
    light_on[0][0] = true;
    ret++;
    
    while (!q.empty()) {
        int curr_r = q.front().first;
        int curr_c = q.front().second;
        q.pop();
        
        // 스위치 켜기
        for (auto next_room: rooms[curr_r][curr_c]) {
            int next_r = next_room.first;
            int next_c = next_room.second;
            int next_idx = next_r*N + next_c;
            
            if (!light_on[next_r][next_c]) ret++;
            light_on[next_r][next_c] = true;
        }
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        // (1,1)과 연결된 방 방문
        for (int r=0; r<N; r++) {
            for (int c=0; c<N; c++) {
                if (!light_on[r][c] || visited[r][c]) continue;
                
                for (int i=0; i<4; i++) {
                    int adj_r = r + dr[i];
                    int adj_c = c + dc[i];
                    
                    if (adj_r < 0 || adj_r >= N || adj_c < 0 || adj_c >= N) continue;
                    
                    if (visited[adj_r][adj_c]) {
                        visited[r][c] = true;
                        q.push({r, c});
                    }
                }
            }
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
        int r, c, nr, nc;
        cin >> r >> c >> nr >> nc;
        r--; c--; nr--; nc--;
        rooms[r][c].push_back({nr, nc});
    }
    
    cout << simulate();

    return 0;
}
