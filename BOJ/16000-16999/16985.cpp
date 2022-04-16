#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int MAX = 5;
const int INF = 987654321;

queue<piii> q;
bool maze[MAX][MAX][MAX], temp[MAX][MAX][MAX], original[MAX][MAX][MAX], visit[MAX][MAX][MAX];
int dist[MAX][MAX][MAX], rotate_count[MAX], order[MAX];

int df[] = {-1, 1, 0, 0, 0, 0};
int dr[] = {0, 0, -1, 1, 0, 0};
int dc[] = {0, 0, 0, 0, -1, 1};

void copy_maze_to_temp(int f) {
    for (int i=0; i<MAX; i++) {
        for (int j=0; j<MAX; j++) {
            temp[f][i][j] = maze[f][i][j];
        }
    }
}

void copy_original_to_maze(int of, int mf) {
    for (int i=0; i<MAX; i++) {
        for (int j=0; j<MAX; j++) {
            maze[mf][i][j] = original[of][i][j];
        }
    }
}

// rotate(f, n): f번째 판을 90*n도 회전 상태로 만들기
void rotate(int f, int n) {
    int opt_n = ((n+4) - rotate_count[f]) % 4;
    rotate_count[f] = n;
    if (opt_n == 0) return;
    
    copy_maze_to_temp(f);
    for (int i=0; i<MAX; i++) {
        for (int j=0; j<MAX; j++){
            switch (opt_n) {
                case 1:
                    maze[f][i][j] = temp[f][MAX-1-j][i];
                    break;
                case 2:
                    maze[f][i][j] = temp[f][MAX-1-i][MAX-1-j];
                    break;
                case 3:
                    maze[f][i][j] = temp[f][j][MAX-1-i];
                    break;
            }
        }
    }
}

int BFS() {
    if (!maze[0][0][0] || !maze[4][4][4]) return INF;
    
    memset(visit, 0, sizeof(visit));
    memset(dist, 0, sizeof(dist));
    while (!q.empty()) q.pop();
    
    visit[0][0][0] = true;
    q.push({0, {0, 0}});
    
    while (!q.empty()) {
        piii curr = q.front(); q.pop();
        int f = curr.first;
        int r = curr.second.first;
        int c = curr.second.second;
        
        if (f == 4 && r == 4 && c == 4) return dist[f][r][c];
        
        for (int i=0; i<6; i++) {
            int next_f = f + df[i];
            int next_r = r + dr[i];
            int next_c = c + dc[i];
            if (next_f < 0 || next_f >= MAX) continue;
            if (next_r < 0 || next_r >= MAX) continue;
            if (next_c < 0 || next_c >= MAX) continue;
            if (!maze[next_f][next_r][next_c] || visit[next_f][next_r][next_c]) continue;
            
            visit[next_f][next_r][next_c] = true;
            dist[next_f][next_r][next_c] = dist[f][r][c] + 1;
            q.push({next_f, {next_r, next_c}});
        }
    }
    
    return INF;
}

// 각 판 회전하기
int DFS(int f) {
    if (f == MAX) return BFS();
    
    int ret = INF;
    for (int i=0; i<4; i++) {
        rotate(f, i);
        ret = min(ret, DFS(f+1));
    }
    
    return ret;
}

// 판 순서 바꾸기
int DDFS(int idx, int used) {
    if (idx == MAX) {
        for (int i=0; i<MAX; i++) copy_original_to_maze(order[i], i);
        memset(rotate_count, 0, sizeof(rotate_count));
        return DFS(0);
    }
    
    int ret = INF;
    for (int i=0; i<MAX; i++) {
        if ((used & (1 << i)) != 0) continue;
        order[idx] = i;
        ret = min(ret, DDFS(idx+1, used|(1<<i)));
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int i=0; i<MAX; i++) {
        for (int j=0; j<MAX; j++) {
            for (int k=0; k<MAX; k++) {
                cin >> original[i][j][k];
            }
        }
    }
    
    int ans = DDFS(0, 0);
    if (ans == INF) cout << -1;
    else cout << ans;

    return 0;
}
