#include <iostream>
#include <vector>

using namespace std;

const int MAX = 19;

int board[MAX][MAX];
bool visited[MAX][MAX][4];
int dr[] = {1, 0, -1, 1};   // 세로, 가로, 7시&1시, 10시&4시
int dc[] = {0, 1, 1, 1};

int check(int r, int c, int dir, int cnt, int color) {
    if (r < 0 || r >= 19 || c < 0 || c >= 19) return cnt;
    if (board[r][c] != color) return cnt;
    
    // dir 방향으로 (r,c)를 탐색한 적이 있음
    visited[r][c][dir] = true;
    
    return check(r + dr[dir], c + dc[dir], dir, cnt+1, color);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i=0; i<MAX; i++) {
        for (int j=0; j<MAX; j++) {
            cin >> board[i][j];
        }
    }
    
    int winner = 0;
    pair<int, int> start_point = {0, 0};
    
    // 가장 왼쪽에 있는 바둑알을 찾기 위해 0열부터 탐색
    for (int j=0; j<MAX; j++) {
        for (int i=0; i<MAX; i++) {
            if (board[i][j] == 0) continue;
            
            for (int d=0; d<4; d++) {
                // d 방향으로 (i, j)를 탐색한 적이 있으면, (i, j)는 시작점이 될 수 없음
                if (visited[i][j][d]) continue;
                
                // 정확히 5개가 일렬로 놓인 경우
                if (check(i, j, d, 0, board[i][j]) == 5) {
                    winner = board[i][j];
                    start_point = {i+1, j+1};
                    break;
                }
            }
        }
    }
    
    cout << winner << "\n";
    if (winner != 0) {
        cout << start_point.first << " " << start_point.second << "\n";
    }

    return 0;
}
