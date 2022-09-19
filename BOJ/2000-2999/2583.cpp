#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N, K;
bool board[100][100];
bool visit[100][100];

int DFS(int r, int c) {
    if (visit[r][c]) return 0;
    visit[r][c] = true;
    
    int ret = 1;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    for (int i=0; i<4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nr >= M || nc < 0 || nc >= N) continue;
        if (visit[nr][nc] || board[nr][nc]) continue;
        ret += DFS(nr, nc);
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> M >> N >> K;
    for (int i=0; i<K; i++) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        for (int r=sy; r<ey; r++) {
            for (int c=sx; c<ex; c++) {
                board[r][c] = true;
            }
        }
    }
    
    vector<int> ans;
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            if (board[i][j] || visit[i][j]) continue;
            ans.push_back(DFS(i, j));
        }
    }
    sort(ans.begin(), ans.end());
    
    cout << ans.size() << "\n";
    for (auto sz: ans) cout << sz << " ";

    return 0;
}
