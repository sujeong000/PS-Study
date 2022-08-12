#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

const int INF = 987654321;

struct Cube {
    int l, r, c;
};

int L, R, C;
string building[30][30];
int visit[30][30][30];
Cube S, E;

int dl[] = {-1, 1, 0, 0, 0, 0};
int dr[] = {0, 0, -1, 1, 0, 0};
int dc[] = {0, 0, 0, 0, -1, 1};

int BFS() {
    queue<Cube> q;
    
    memset(visit, 0, sizeof(visit));
    q.push(S);
    
    while (!q.empty()) {
        Cube curr = q.front(); q.pop();
        int l = curr.l;
        int r = curr.r;
        int c = curr.c;
        
        if (E.l == l && E.r == r && E.c == c) return visit[l][r][c];
        
        for (int i=0; i<6; i++) {
            int nl = l + dl[i];
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (nl < 0 || nl >= L) continue;
            if (nr < 0 || nr >= R) continue;
            if (nc < 0 || nc >= C) continue;
            if (visit[nl][nr][nc]) continue;
            if (building[nl][nr][nc] == '#') continue;
            
            q.push({nl, nr, nc});
            visit[nl][nr][nc] = visit[l][r][c] + 1;
        }   
    }
    
    return INF;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while (true) {
        cin >> L >> R >> C;
        
        if (L + R + C == 0) break;
        
        for (int i=0; i<L; i++) {
            for (int j=0; j<R; j++) {
                cin >> building[i][j];
                
                for (int k=0; k<C; k++) {
                    if (building[i][j][k] == 'S') S = {i, j, k};
                    else if (building[i][j][k] == 'E') E = {i, j, k};
                }
            }
        }
        
        int ans = BFS();
        
        if (ans == INF) cout << "Trapped!\n";
        else cout << "Escaped in " << ans << " minute(s).\n";
    }
    
    return 0;
}
