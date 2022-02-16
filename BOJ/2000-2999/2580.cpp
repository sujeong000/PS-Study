#include <iostream>
#include <vector>

using namespace std;

int sudoku[9][9];
bool finish;

bool check(int r, int c, int n) {
    int block_r = r / 3;
    int block_c = c / 3;
    
    for(int i=0; i<9; i++) {
        if (sudoku[r][i] == n) return false;
        if (sudoku[i][c] == n) return false;
        if (sudoku[block_r*3+i/3][block_c*3+i%3] == n) return false;
    }
    
    return true;
}

void fill(int r, int c) {
    if (finish) return;
    
    if (r == 9) {
        finish = true;
        
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                cout << sudoku[i][j] << " ";
            }
            cout << "\n";
        }
        
        return;
    }
    
    int next_r = (r * 9 + c + 1) / 9;
    int next_c = (r * 9 + c + 1) % 9;
    
    if (sudoku[r][c] != 0) {
        fill(next_r, next_c);    
    }
    else {
        for(int i=1; i<=9; i++) {
            if (!check(r, c, i)) continue;
            
            sudoku[r][c] = i;
            fill(next_r, next_c);
            sudoku[r][c] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cin >> sudoku[i][j];
        }
    }
    
    fill(0, 0);

    return 0;
}
