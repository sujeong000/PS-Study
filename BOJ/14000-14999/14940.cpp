#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

const int MAX_N = 1000;
const int POSSIBLE = 1, GOAL = 2;

int n, m;
int goal_r, goal_c;
int board[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void calcDist() {
    queue<pii> q;
    
    // 1. BFS로 목표지점과의 거리 계산
    q.push({goal_r, goal_c});
    
    while (!q.empty()) {
        pii curr = q.front(); q.pop();
        int r = curr.first;
        int c = curr.second;
        
        for (int i=0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (board[nr][nc] == POSSIBLE && dist[nr][nc] == 0) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    
    // 2. 도달할 수 없는 위치 처리
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (board[i][j] == POSSIBLE && dist[i][j] == 0) {
                dist[i][j] = -1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> board[i][j];
            
            if (board[i][j] == GOAL) {
                goal_r = i;
                goal_c = j;
            }
        }
    }
    
    calcDist();
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}
