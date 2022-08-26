#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int N, M;
int parent[10000], sz[10000];
vector<pii> rooms[100][100];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    a = find(a); b = find(b);
    
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    
    parent[b] = a;
    sz[a] += sz[b];
}

void init_union_find() {
    for (int i=0; i<10000; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int simulate() {
    int ret = 0;
    queue<pii> q;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<vector<bool>> light_on(N, vector<bool>(N, false));
    
    init_union_find();
    
    q.push({0, 0});
    visited[0][0] = true;
    light_on[0][0] = true;
    ret++;
    
    while (!q.empty()) {
        int curr_r = q.front().first;
        int curr_c = q.front().second;
        q.pop();
        
        for (auto next_room: rooms[curr_r][curr_c]) {
            // (curr_r, curr_c)에서 불 켤 수 있는 방
            int next_r = next_room.first;
            int next_c = next_room.second;
            int next_idx = next_r*N + next_c;
            
            if (!light_on[next_r][next_c]) ret++;
            light_on[next_r][next_c] = true;
            
            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};
            
            // 인접한 불켜진 방과 경로 연결
            for (int i=0; i<4; i++) {
                int adj_r = next_r + dr[i];
                int adj_c = next_c + dc[i];
                int adj_idx = adj_r*N + adj_c;
                
                if (adj_r < 0 || adj_r >= N || adj_c < 0 || adj_c >= N) continue;
                
                if (light_on[adj_r][adj_c]) {
                    merge(next_idx, adj_idx);
                }
            }
        }
        
        // (1,1)과 연결되어 있는 방 방문
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (!light_on[i][j] || visited[i][j]) continue;
                if (find(i*N+j) == find(0)) {
                    q.push({i, j});
                    visited[i][j] = true;
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
