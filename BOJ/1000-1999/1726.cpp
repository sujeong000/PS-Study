#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int INF = 987654321;

struct Node {
    int r, c, d;
};

int M, N;
bool board[101][101];

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

Node makeNode(int r, int c, int d) {
    r--; c--;
    
    switch (d) {
        case 1: d = 0; break;
        case 2: d = 2; break;
        case 3: d = 1; break;
        case 4: d = 3; break;
        default: d = -1; 
    }
    
    return {r, c, d};
}

bool validate(int r, int c, int d, const vector<vector<vector<int>>>& dist) {
    if (r < 0 || r >= M || c < 0 || c >= N) return false;
    if (board[r][c] == 1) return false;
    if (dist[r][c][d] != INF) return false;
    return true;
}

int BFS(Node from, Node to) {
    queue<Node> q;
    vector<vector<vector<int>>> dist(M, vector<vector<int>>(N, vector<int>(4, INF)));
    
    q.push(from);
    dist[from.r][from.c][from.d] = 0;
    
    while (!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int d = q.front().d;
        q.pop();
        
        if (r == to.r && c == to.c && d == to.d) return dist[r][c][d];
        
        // go k
        for (int i=1; i<=3; i++) {
            int nr = r + dr[d]*i;
            int nc = c + dc[d]*i;
            int nd = d;
            
            if (board[nr][nc] == 1) break;
            if (!validate(nr, nc, nd, dist)) continue;
            
            dist[nr][nc][nd] = dist[r][c][d] + 1;
            q.push({nr, nc, nd});
        }
        
        // turn l/r
        for (int i=1; i<=3; i+=2) {
            int nr = r;
            int nc = c;
            int nd = (d+i) % 4;
            
            if (!validate(nr, nc, nd, dist)) continue;
            
            dist[nr][nc][nd] = dist[r][c][d] + 1;
            q.push({nr, nc, nd});
        }
    }
    
    return INF;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> M >> N;
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            cin >> board[i][j];
        }
    }
    
    int sr, sc, sd, er, ec, ed;
    cin >> sr >> sc >> sd;
    cin >> er >> ec >> ed;
    
    cout << BFS(makeNode(sr, sc, sd), makeNode(er, ec, ed));

    return 0;
}
