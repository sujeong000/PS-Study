#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int WATER = 0, IMPOSSIBLE = 1, POSSIBLE = 2;
const int GREEN = 0, RED = 1;
typedef pair<int, int> pii;

struct Node {
    int color, r, c;
};

int N, M, G, R;
int board[50][50];
vector<pii> startPos;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int countOne(int mask) {
    int ret = 0;
    
    while (mask > 0) {
        ret += mask % 2;
        mask /= 2;
    }
    
    return ret;
}

int simulate(int green, int red) {
    queue<Node> q;
    vector<vector<vector<int>>> visit(2, vector<vector<int>>(50, vector<int>(50, 0)));
    int P = startPos.size();
    int flowerCnt = 0;
    
    for (int i=0; i<P; i++) {
        int r = startPos[i].first;
        int c = startPos[i].second;
        
        if ((green & (1 << i)) != 0) {
            q.push({GREEN, r, c});
            visit[GREEN][r][c] = 1;
        }
        if ((red & (1 << i)) != 0) {
            q.push({RED, r, c});
            visit[RED][r][c] = 1;
        }
    }
    
    while (!q.empty()) {
        int color = q.front().color;
        int r = q.front().r;
        int c = q.front().c;
        int v = visit[color][r][c];
        q.pop();
        
        if (visit[GREEN][r][c] == visit[RED][r][c]) {
            flowerCnt++;
            continue;
        }
        
        for (int i=0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if (board[nr][nc] == WATER || visit[color][nr][nc]) continue;
            if (visit[1-color][nr][nc] && visit[1-color][nr][nc] != v+1) continue;
            
            q.push({color, nr, nc});
            visit[color][nr][nc] = v+1;
        }
    }
    
    return flowerCnt / 2;
}

void findStartPos() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (board[i][j] == POSSIBLE) {
                startPos.push_back({i, j});
            }
        }
    }
}

int solution() {
    findStartPos();
    
    int P = startPos.size();
    int maxFlower = 0;
    
    for (int i=0; i<(1 << P); i++) {
        for (int j=0; j<(1 << P); j++) {
            if (countOne(i) == G && countOne(j) == R && countOne(i|j) == G+R) {
                maxFlower = max(maxFlower, simulate(i, j));
            }
        }
    }
    
    return maxFlower;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> G >> R;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> board[i][j];
        }
    }
    
    cout << solution();

    return 0;
}
