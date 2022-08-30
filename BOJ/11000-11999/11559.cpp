#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

string field[12];

void gravity() {
    for (int j=0; j<6; j++) {
        for (int i=10; i>=0; i--) {
            int r = i;
            
            while (r+1 < 12 && field[r+1][j] == '.') {
                field[r+1][j] = field[r][j];
                field[r][j] = '.';
                r++;
            }
        }
    }
}

int DFS(int r, int c, vector<vector<bool>>& visited) {
    int ret = 1;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    
    visited[r][c] = true;
    
    for (int i=0; i<4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if (nr < 0 || nr >= 12 || nc < 0 || nc >= 6) continue;
        if (field[nr][nc] != field[r][c]) continue;
        if (visited[nr][nc]) continue;
        
        ret += DFS(nr, nc, visited);
    }
    
    return ret;
}

bool explode() {
    bool ret = false;
    
    for (int i=0; i<12; i++) {
        for (int j=0; j<6; j++) {
            if (field[i][j] == '.') continue;
            
            vector<vector<bool>> visited(12, vector<bool>(6, 0));
            
            if (DFS(i, j, visited) >= 4) {
                ret = true;
                
                for (int r=0; r<12; r++) {
                    for (int c=0; c<6; c++) {
                        if (visited[r][c]) {
                            field[r][c] = '.';
                        }
                    }
                }
            }
        }
    }
    
    return ret;
}

int simulate() {
    int combo = 0;
    
    while (explode()) {
        combo++;
        gravity();
    }
    
    return combo;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int i=0; i<12; i++) {
        cin >> field[i];
    }
    
    cout << simulate();

    return 0;
}
