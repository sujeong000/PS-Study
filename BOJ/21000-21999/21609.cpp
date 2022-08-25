#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, pii> piiii;
const int BLACK = -1, RAINBOW = 0, EMPTY = -2;

int N, M;
int board[20][20];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

pii DFS(int r, int c, int color, vector<vector<bool>>& visited) {
    pii ret = {1, board[r][c] == RAINBOW ? 1 : 0};
    
    visited[r][c] = true;
    
    for (int i=0; i<4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
        if (board[nr][nc] == BLACK) continue;
        if (board[nr][nc] != RAINBOW && board[nr][nc] != color) continue;
        if (visited[nr][nc]) continue;
        
        auto res = DFS(nr, nc, color, visited);
        ret.first += res.first;
        ret.second += res.second;
    }
    
    return ret;
}

piiii findLargestGroup() {
    vector<vector<bool>> checked(N, vector<bool>(N, 0));
    vector<vector<pii>> group_size(N, vector<pii>(N, {0, 0}));
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            // 무지개는 기준 블록이 될 수 없음
            if (board[i][j] <= 0 || checked[i][j]) continue;
            
            vector<vector<bool>> visited(N, vector<bool>(N, 0));
            group_size[i][j] = DFS(i, j, board[i][j], visited);
            for (int r=0; r<N; r++) {
                for (int c=0; c<N; c++) {
                    if (visited[r][c]) checked[r][c] = true;
                }
            }
        }
    }
    
    pair<int, int> largest_group = {-1, -1};
    pii largest_size = {-1, -1};
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (!checked[i][j]) continue;
            if (group_size[i][j] >= largest_size) {
                largest_size = group_size[i][j];
                largest_group = {i, j};
            }
        }
    }
    
    return {largest_size, largest_group};
}

void removeLargestGroup(int r, int c) {
    vector<vector<bool>> visited(N, vector<bool>(N, 0));
    
    DFS(r, c, board[r][c], visited);
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (visited[i][j]) {
                board[i][j] = EMPTY;
            }
        }
    }
}

void applyGravity() {
    for (int c=0; c<N; c++) {
        for (int i=N-2; i>=0; i--) {
            if (board[i][c] < 0) continue;
            
            int r = i;
            while (r < N-1 && board[r+1][c] == EMPTY) {
                board[r+1][c] = board[r][c];
                board[r][c] = EMPTY;
                r++;
            }
        }      
    }
}

void rotate() {
    vector<vector<int>> temp(N, vector<int>(N));
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            temp[N-1-j][i] = board[i][j];
        }
    }
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            board[i][j] = temp[i][j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> board[i][j];
        }
    }
    
    int score = 0;
    
    while (true) {
        auto largest_group = findLargestGroup();
        pii largest_size = largest_group.first;
        int r = largest_group.second.first;
        int c = largest_group.second.second;
        
        if (largest_size.first < 2) break;
        
        removeLargestGroup(r, c);
        applyGravity();
        rotate();
        applyGravity();
        
        score += largest_size.first * largest_size.first;
    }
    
    cout << score;

    return 0;
}
