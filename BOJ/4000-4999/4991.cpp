#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 987654321;

int W, H;
string room[20];
vector<pii> dirty;
pii start;
int cache[20][20][1 << 10], dist[20][20][20][20];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int calcDist(int fromR, int fromC, int toR, int toC) {
    int& ret = dist[fromR][fromC][toR][toC];
    if (ret != -1) return ret;
    
    queue<piii> q;
    vector<vector<bool>> visit(20, vector<bool> (20, 0));
    q.push({0, {fromR, fromC}});
    visit[fromR][fromC] = true;
    
    while (!q.empty()) {
        int d = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();
        
        if (r == toR && c == toC) return ret = d;
        
        for (int i=0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
            if (room[nr][nc] == 'x' || visit[nr][nc]) continue;
            
            q.push({d+1, {nr, nc}});
            visit[nr][nc] = true;
        }
    }
    
    return ret = INF;
}

// dp(r, c, mask):
// 현재 위치가 (r,c)이고 더러운 칸들의 방문여부가 mask일 때
// 모두 깨끗한 칸으로 만드는데 필요한 이동 횟수의 최솟값
int dp(int r, int c, int mask) {
    if (mask == ((1 << dirty.size()) - 1)) return 0;
    
    int& ret = cache[r][c][mask];
    if (ret != -1) return ret;
    
    ret = INF;
    for (int i=0; i<dirty.size(); i++) {
        if ((mask & (1 << i)) != 0) continue;
        int nr = dirty[i].first;
        int nc = dirty[i].second;
        int d = calcDist(r, c, nr, nc);
        
        if (d != INF) ret = min(ret, d + dp(nr, nc, mask|(1 << i)));
    }
    
    return ret;
}

void initTestcase() {
    memset(cache, -1, sizeof(cache));
    memset(dist, -1, sizeof(dist));
    dirty.clear();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while (true) {
        initTestcase();
        
        cin >> W >> H;
        if (W == 0 && H == 0) break;
        
        for (int i=0; i<H; i++) {
            cin >> room[i];
            
            for (int j=0; j<W; j++) {
                if (room[i][j] == '*') {
                    dirty.push_back({i, j});
                }
                else if (room[i][j] == 'o') {
                    start = {i, j};
                }
            }
        }
        
        int ans = dp(start.first, start.second, 0);
        
        if (ans == INF) cout << -1 << "\n";
        else cout << ans << "\n";
    }

    return 0;
}
