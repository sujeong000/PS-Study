#include <iostream>
#include <string.h>

using namespace std;

int R, C;
int last_count, hour = 0;
int board[100][100];
int visit[100][100];

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

void DFS(int r, int c) {
    visit[r][c] = true;
    board[r][c] = -1;
    
    for(int i=0; i<4; i++) {
        int next_r = r + dr[i];
        int next_c = c + dc[i];
        
        if (next_r < 0 || next_r >= R || next_c < 0 || next_c >= C) continue;
        if (visit[next_r][next_c] || board[next_r][next_c] == 1) continue;
        
        DFS(next_r, next_c);
    }
}

void contact_air() {
    memset(visit, 0, sizeof(visit));
    
    DFS(0, 0);
}

bool melt_cheese() {
    int count = 0;
    
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if (board[i][j] != 1) continue;
           
            count++;
           
            for(int k=0; k<4; k++) {
               int adj_r = i + dr[k];
               int adj_c = j + dc[k];
               
               if (board[adj_r][adj_c] == -1) board[i][j] = 0;
            }
        }
    }
    
    if (count == 0) return false;
    
    last_count = count;
    hour++;
    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> R >> C;
    
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin >> board[i][j];
        }
    }
    
    do {
        contact_air();
    } while (melt_cheese());
    
    cout << hour << "\n";
    cout << last_count << "\n";

    return 0;
}
