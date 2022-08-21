#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

string board[5];
bool isPicked[5][5];
int psum[25];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool checkAdjacent() {
    queue<pii> q;
    vector<vector<bool>> visit(5, vector<bool>(5, 0));
    
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            if (isPicked[i][j] && q.empty()) {
                q.push({i, j});
                visit[i][j] = true;
                break;
            }
        }
    }
    
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        for (int i=0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;
            if (!isPicked[nr][nc]) continue;
            if (visit[nr][nc]) continue;
            
            q.push({nr, nc});
            visit[nr][nc] = true;
        }
    }
    
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            if (!isPicked[i][j]) continue;
            if (!visit[i][j]) return false;
        }
    }
    
    return true;
}

int DFS(int idx, int cnt, int sCnt) {
    if (cnt == 7) {
        if (sCnt >= 4 && checkAdjacent()) return 1;
        else return 0;
    }
    if (idx == 25) return 0;
    if (idx != 0 && psum[24]-psum[idx-1]+sCnt < 4) return 0;    // 남은 S 개수
    if (25-idx+cnt < 7) return 0;                               // 남은 사람 수
    
    int ret = 0;
    
    int r = idx/5;
    int c = idx%5;
    
    isPicked[r][c] = true;
    ret += DFS(idx+1, cnt+1, sCnt + (board[r][c] == 'S' ? 1 : 0));
    isPicked[r][c] = false;
    ret += DFS(idx+1, cnt, sCnt);
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int i=0; i<5; i++) {
        cin >> board[i];
    }
    
    for (int i=0; i<25; i++) {
        int prev = (i == 0) ? 0 : psum[i-1];
        psum[i] = (board[i/5][i%5] == 'S') ? prev+1 : prev;
    }
    
    cout << DFS(0, 0, 0);

    return 0;
}
