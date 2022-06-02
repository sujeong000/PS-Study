#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

const int MAX = 301, WATER = 0;

struct Ice {
    int r, c, h;
};

int N, M;
int board[MAX][MAX];
vector<Ice> ice;
bool visit[MAX][MAX];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void DFS(int r, int c) {
    visit[r][c] = true;
    
    for (int i=0; i<4; i++) {
        int adjR = r + dr[i];
        int adjC = c + dc[i];
        
        if (visit[adjR][adjC] || board[adjR][adjC] == WATER) continue;
        
        DFS(adjR, adjC);
    }
}

// check(): 빙산 덩어리가 2개 이상인지 체크
bool check() {
    memset(visit, 0, sizeof(visit));
    
    bool dfs = false;
    for (auto x: ice) {
        if (visit[x.r][x.c] || x.h == 0) continue;
        if (dfs) return true;
        
        DFS(x.r, x.c);
        dfs = true;
    }
    
    return false;
}

// melt(idx): idx번째 빙산을 녹인다
void melt(int idx) {
    int r = ice[idx].r;
    int c = ice[idx].c;
    int h = ice[idx].h;
    
    for (int i=0; i<4; i++) {
        int adjR = r + dr[i];
        int adjC = c + dc[i];
        if (board[adjR][adjC] == WATER) h--;
    }
    
    ice[idx].h = max(0, h);
}

int simulate() {
    int ret = 1;
    
    while (true) {
        for (int i=0; i<ice.size(); i++) melt(i);
        
        bool finish = true;
        for (int i=0; i<ice.size(); i++) {
            int r = ice[i].r;
            int c = ice[i].c;
            int h = ice[i].h;
            board[r][c] = h;
            
            if (h > 0) finish = false;
        }
        
        if (check()) return ret;
        if (finish) return 0;
        
        ret++;
    }
    
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> board[i][j];
            if (board[i][j] > 0) ice.push_back({i, j, board[i][j]});
        }
    }
    
    cout << simulate();
    
    return 0;
}
