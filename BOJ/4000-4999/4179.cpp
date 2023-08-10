#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1001;
const int INF = 987654321;
typedef pair<int, int> pii;

int R, C;
pii J;
vector<pii> fires;
int board[MAX][MAX];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

// simulateFire(): 각 칸에 불이 번지는 시간을 시뮬레이션 함
void simulateFire() {
    queue<pii> q;
    
    for (auto fire: fires) {
        q.push(fire);
        board[fire.first][fire.second] = 0;
    }
    
    while (!q.empty()) {
        pii curr = q.front(); q.pop();
        int r = curr.first;
        int c = curr.second;
        
        for (int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (board[nr][nc] != INF) continue;
            
            board[nr][nc] = board[r][c] + 1;
            q.push({nr, nc});
        }
    }
}

int solution() {
    queue<pii> q;
    
    simulateFire();
    
    q.push(J);
    board[J.first][J.second] = 0;
    
    while (!q.empty()) {
        pii curr = q.front(); q.pop();
        int r = curr.first;
        int c = curr.second;
        
        for (int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            // 탈출 성공
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) return board[r][c] + 1;
            // 이미 불이 번져있는 곳이라면 갈 수 없음
            if (board[nr][nc] <= board[r][c]+1) continue;
            
            board[nr][nc] = board[r][c] + 1;
            q.push({nr, nc});
        }
    }
    
    return INF;
}

int main() {
    cin >> R >> C;
    for (int i=0; i<R; i++) {
        string temp;
        cin >> temp;
        
        for (int j=0; j<C; j++) {
            board[i][j] = INF;
            
            if (temp[j] == '#') board[i][j] = 0;
            else if (temp[j] == 'J') J = {i, j};
            else if (temp[j] == 'F') fires.push_back({i, j});
        }
    }
    
    int answer = solution();
    
    if (answer == INF) cout << "IMPOSSIBLE";
    else cout << answer;
    
    return 0;
}
