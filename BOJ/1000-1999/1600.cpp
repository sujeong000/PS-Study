#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

struct Node {
    int r, c, k;  
};

int K, W, H;
int board[200][200];
bool visit[200][200][31];

int dr[] = {-1, 1, 0, 0, -2, -2, -1, -1, 1, 1, 2, 2};
int dc[] = {0, 0, -1, 1, -1, 1, -2, 2, -2, 2, -1, 1};

int BFS(pii s, pii e) {
    queue<pair<int, Node>> q;
    
    q.push({0, {s.first, s.second, 0}});
    visit[s.first][s.second][0] = true;
    
    while (!q.empty()) {
        int dist = q.front().first;
        Node node = q.front().second;
        q.pop();
        
        if (node.r == e.first && node.c == e.second) return dist;
        
        for (int i=0; i<(node.k < K ? 12 : 4); i++) {
            int nr = node.r + dr[i];
            int nc = node.c + dc[i];
            int nk = i >= 4 ? node.k+1 : node.k;
            if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
            if (visit[nr][nc][nk] || board[nr][nc] == 1) continue;
            
            q.push({dist+1, {nr, nc, nk}});
            visit[nr][nc][nk] = true;
        }
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> K >> W >> H;
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            cin >> board[i][j];
        }
    }
    
    cout << BFS({0, 0}, {H-1, W-1});

    return 0;
}
