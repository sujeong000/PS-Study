#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

typedef struct {
    int t, r, c;
} Node;

string board[9][8];
int dr[] = {-1, 1, 0, 0, 0, -1, -1, 1, 1};
int dc[] = {0, 0, -1, 1, 0, -1, 1, -1, 1};

bool bfs(pii from, pii to) {
    queue<Node> q;
    vector<vector<vector<bool>>> visit(9, vector<vector<bool>>(8, vector<bool>(8, 0)));
    
    q.push({0, from.first, from.second});
    visit[0][from.first][from.second] = true;
    
    while (!q.empty()) {
        int t = q.front().t;
        int r = q.front().r;
        int c = q.front().c;
        q.pop();
        
        if (r == to.first && c == to.second) return true;
        if (board[t][r][c] == '#') continue;
        
        for (int i=0; i<9; i++) {
            int nt = min(8, t + 1);
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (nr < 0 || nr >= 8 || nc < 0 || nc >= 8) continue;
            if (board[t][nr][nc] == '#' || visit[nt][nr][nc]) continue;
            
            q.push({nt, nr, nc});
            visit[nt][nr][nc] = true;
        }
    }
    
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int i=0; i<8; i++) {
        cin >> board[0][i];
    }
    
    for (int t=1; t<=8; t++) {
        for (int i=0; i<8; i++) {
            for (int j=0; j<8; j++) {
                if (i-1 < 0) board[t][i][j] = '.';
                else board[t][i][j] = board[t-1][i-1][j];
            }
        }
    }
    
    cout << bfs({7, 0}, {0, 7});

    return 0;
}
