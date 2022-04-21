#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> piiii;
const int INF = 987654321;

int W, H, R, C;
char board[100][100];
int dist[100][100][4];
queue<piiii> q;
vector<pii> c;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, 1, -1};

void bfs() {
    for (int i=0; i<4; i++) {
        dist[R][C][i] = 0;
        q.push({{R, C}, {i, 0}});
    }
    
    while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int dir = q.front().second.first;
        int d = q.front().second.second;
        q.pop();
        
        for (int i=0; i<4; i++) {
            int next_r = r + dr[i];
            int next_c = c + dc[i];
            int next_dir = i;
            int next_d = d + (dir == i ? 0 : 1);
            
            if (next_r < 0 || next_r >= H || next_c < 0 || next_c >= W) continue;
            if (board[next_r][next_c] == '*') continue;
            if (next_d >= dist[next_r][next_c][next_dir]) continue;
            
            dist[next_r][next_c][next_dir] = next_d;
            q.push({{next_r, next_c}, {next_dir, next_d}});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> W >> H;
    for (int i=0; i<H; i++) {
        string s;
        cin >> s;
        for (int j=0; j<W; j++) {
            board[i][j] = s[j];
            if (board[i][j] == 'C') c.push_back({i, j});
        }
    }
    
    R = c[0].first;
    C = c[0].second;
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            for (int k=0; k<4; k++) {
                dist[i][j][k] = INF;
            }
        }
    }
    
    bfs();

    R = c[1].first;
    C = c[1].second;
    int ans = INF;
    for (int i=0; i<4; i++) ans = min(ans, dist[R][C][i]);
    cout << ans;

    return 0;
}
