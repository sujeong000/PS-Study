#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;
const int INF = 987654321;

int N, M;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

pii findStartPoint(vector<string>& board) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (board[i][j] == 'R') return {i, j};        
        }
    }
    
    return {0, 0};
}

bool check(int r, int c, vector<string>& board) {
    if (r < 0 || r >= N || c < 0 || c >= M) return false;
    if (board[r][c] == 'D') return false;
    return true;
}

int calcMinDist(vector<string>& board) {
    vector<vector<int>> dist(N+1, vector<int>(M+1, INF));
    queue<pii> q;
    
    pii startPoint = findStartPoint(board);
    q.push(startPoint);
    dist[startPoint.first][startPoint.second] = 0;
    
    while (!q.empty()) {
        pii curr = q.front(); q.pop();
        int r = curr.first;
        int c = curr.second;
        
        if (board[r][c] == 'G') return dist[r][c];
        
        for (int i=0; i<4; i++) {
            int nr = r;
            int nc = c;
            
            // 장애물이나 맨 끝까지 이동
            while (check(nr+dr[i], nc+dc[i], board)) {
                nr += dr[i];
                nc += dc[i];
            }
            
            if (dist[nr][nc] != INF) continue;
            
            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }
    
    return -1;
}

int solution(vector<string> board) {
    int answer = 0;
    N = board.size();
    M = board[0].size();
    
    answer = calcMinDist(board);
    
    return answer;
}
