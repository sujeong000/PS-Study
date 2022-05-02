#include <iostream>
#include <string.h>

using namespace std;

int W, H;
bool board[51][51], visit[51][51];
int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};

void DFS(int r, int c) {
    visit[r][c] = true;
    
    for (int i=0; i<8; i++) {
        int next_r = r + dr[i];
        int next_c = c + dc[i];
        
        if (0 > next_r || next_r >= H || 0 > next_c || next_c >= W) continue;
        if (visit[next_r][next_c] || !board[next_r][next_c]) continue;
        
        DFS(next_r, next_c);
    }
}

int solution() {
    int ret = 0;
    
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            if (visit[i][j] || !board[i][j]) continue;
            DFS(i, j);
            ret++;
        }
    }
    
    return ret;
}

void init_testcase() {
    memset(visit, 0, sizeof(visit));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while (true) {
        init_testcase();
        
        cin >> W >> H;
        if (W == 0 && H == 0) break;

        for (int i=0; i<H; i++) {
            for (int j=0; j<W; j++) {
                cin >> board[i][j];
            }
        }
        
        cout << solution() << "\n";
    }

    return 0;
}
