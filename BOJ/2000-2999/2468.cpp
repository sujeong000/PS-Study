#include <iostream>
#include <string.h>

using namespace std;

const int MAX = 101;

int N;
int board[MAX][MAX];
bool visit[MAX][MAX];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void DFS(int r, int c, int h) {
    visit[r][c] = true;
    
    for (int i=0; i<4; i++) {
        int next_r = r + dr[i];
        int next_c = c + dc[i];
        
        if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= N) continue;
        if (board[next_r][next_c] <= h || visit[next_r][next_c]) continue;
        DFS(next_r, next_c, h);
    }
}

int find_max_safe_area() {
    int ret = 1;
    
    for (int h=1; h<MAX; h++) {
        int cnt = 0;
        
        memset(visit, 0, sizeof(visit));
        for (int r=0; r<N; r++) {
            for (int c=0; c<N; c++) {
                if (visit[r][c] || board[r][c] <= h) continue;
                
                DFS(r, c, h);
                cnt++;
            }
        }
        
        ret = max(ret, cnt);
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> board[i][j];
        }
    }
    
    cout << find_max_safe_area();

    return 0;
}
