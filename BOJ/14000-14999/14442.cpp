#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int N, M, K;
bool board[1000][1000];
int dist[1000][1000][11];   // dist[r][c][w]: (r,c)까지 w개의 벽을 부수고 오는 최단거리
queue<pair<pii, int>> q;

int INF = 987654321;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int BFS() {
    for(int i=0; i<1000; i++) {
        for(int j=0; j<1000; j++) {
            for(int k=0; k<11; k++) {
                dist[i][j][k] = INF;
            }
        }
    }
    
    int min_dist = INF;
    
    q.push({{0, 0}, 0});
    dist[0][0][0] = 1;
    
    while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int w = q.front().second;
        q.pop();
        
        if (r == N-1 && c == M-1) min_dist = min(min_dist, dist[r][c][w]);
        
        for(int i=0; i<4; i++) {
            int next_r = r + dr[i];
            int next_c = c + dc[i];
            
            if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= M) continue;
            
            if (board[next_r][next_c] == 0) {
                if (dist[r][c][w] + 1 < dist[next_r][next_c][w]) {
                    q.push({{next_r, next_c}, w});
                    dist[next_r][next_c][w] = dist[r][c][w] + 1;
                }
            }
            else {
                if (w < K && dist[r][c][w] + 1 < dist[next_r][next_c][w+1]) {
                    q.push({{next_r, next_c}, w+1});
                    dist[next_r][next_c][w+1] = dist[r][c][w] + 1;
                }
            }
        }
    }
    
    if (min_dist == INF) return -1;
    else return min_dist;
}

int main()
{
    cin >> N >> M >> K;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            int x;
            scanf("%1d", &x);
            board[i][j] = x;
        }
    }
    
    cout << BFS();

    return 0;
}
