#include <iostream>
#include <string.h>

using namespace std;

int N, T;
int board[9][9];
bool used[10][10];
bool solved;

int dr[] = {0, 1};
int dc[] = {1, 0};

void initTestcase() {
    solved = false;
    memset(board, 0, sizeof(board));
    memset(used, 0, sizeof(used));
}

bool checkRow(int n, int row) {
    for (int i=0; i<9; i++) {
        if (board[row][i] == n) return false;
    }
    
    return true;
}

bool checkCol(int n, int col) {
    for (int i=0; i<9; i++) {
        if (board[i][col] == n) return false;
    }
    
    return true;
}

bool checkBlock(int n, int r, int c) {
    int sr = r/3, sc = c/3;
    
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (board[sr*3+i][sc*3+j] == n) return false;
        }
    }
    
    return true;
}

void printBoard() {
    cout << "Puzzle " << T++ << "\n";
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

void DFS(int r, int c) {
    if (solved) return;
    if (r == 9) {
        printBoard();
        solved = true;
        
        return;
    }
    
    int idx = r*9 + c + 1;
    int nr = idx / 9;
    int nc = idx % 9;
    
    if (board[r][c] != 0) {
        DFS(nr, nc);
        return;
    }
    
    for (int i=1; i<=9; i++) {
        if (!checkRow(i, r)) continue;
        if (!checkCol(i, c)) continue;
        if (!checkBlock(i, r, c)) continue;
        
        for (int j=1; j<=9; j++) {
            if (i == j || used[i][j]) continue;
            
            // 가로/세로 배치
            for (int k=0; k<2; k++) {
                int adjR = r + dr[k];
                int adjC = c + dc[k];
                
                if (adjR < 0 || adjR >= 9 || adjC < 0 || adjC >= 9) continue;
                if (board[adjR][adjC] != 0) continue;
                if (!checkRow(j, adjR)) continue;
                if (!checkCol(j, adjC)) continue;
                if (!checkBlock(j, adjR, adjC)) continue;
                
                board[r][c] = i;
                board[adjR][adjC] = j;
                used[i][j] = true;
                used[j][i] = true;
                
                DFS(nr, nc);
                
                board[r][c] = 0;
                board[adjR][adjC] = 0;
                used[i][j] = false;
                used[j][i] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    T = 1;
    
    while (true) {
        initTestcase();
        
        cin >> N;
        if (N == 0) break;
        
        for (int i=0; i<N; i++){
            int u, v;
            string lu, lv;
            cin >> u >> lu >> v >> lv;
            
            board[lu[0]-'A'][lu[1]-'1'] = u;
            board[lv[0]-'A'][lv[1]-'1'] = v;
            used[u][v] = true;
            used[v][u] = true;
        }
        
        for (int i=1; i<=9; i++) {
            string pos;
            cin >> pos;
            
            board[pos[0]-'A'][pos[1]-'1'] = i;
        }
        
        DFS(0, 0);
    }
    
    return 0;
}
