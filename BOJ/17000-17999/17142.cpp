#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
const int EMPTY = 0, WALL = 1, AVAILABLE = 2;
const int INF = 987654321;

int N, M;
int board[50][50];
vector<pii> availables;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int simulate(vector<pii> virus) {
    int ret = 0;
    vector<vector<int>> visit(N, vector<int>(N, INF));
    queue<pii> q;
    
    for (auto v: virus) {
        q.push(v);
        visit[v.first][v.second] = 0;
    }
    
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        for (int i=0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if (board[nr][nc] == WALL) continue;
            if (visit[nr][nc] != INF) continue;
            
            visit[nr][nc] = visit[r][c] + 1;
            q.push({nr, nc});
        }
    }
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (board[i][j] != EMPTY) continue;
            ret = max(ret, visit[i][j]);
        }
    }
    
    return ret;
}

int DFS(int idx, vector<pii> pick) {
    if (idx == availables.size()) {
        return (pick.size() == M) ? simulate(pick) : INF;
    }
    
    int ret = INF;
    
    ret = min(ret, DFS(idx+1, pick));
    pick.push_back(availables[idx]);
    ret = min(ret, DFS(idx+1, pick));
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> board[i][j];
            if (board[i][j] == AVAILABLE) {
                availables.push_back({i, j});
            }
        }
    }
    
    int ans = DFS(0, {});
    
    if (ans == INF) cout << -1;
    else cout << ans;

    return 0;
}
