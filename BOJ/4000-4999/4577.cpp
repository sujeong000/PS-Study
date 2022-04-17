#include <iostream>

using namespace std;

const int MAX = 16;

int R, C, r, c, box_num, box_cnt;
string s, m;
char board[MAX][MAX];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, 1, -1};

void move_box(int row, int col, int dir) {
    int next_row = row + dr[dir];
    int next_col = col + dc[dir];
    
    switch (board[next_row][next_col]) {
        case '.':
            board[next_row][next_col] = 'b';
            break;
        case '+':
            board[next_row][next_col] = 'B';
            box_cnt++;
            break;
        default:
            return;
    }
    
    switch (board[row][col]) {
        case 'b':
            board[row][col] = '.';
            break;
        case 'B':
            board[row][col] = '+';
            box_cnt--;
            break;
    }
}

void move_character(int nr, int nc) {
    switch (board[nr][nc]) {
        case '.':
            board[nr][nc] = 'w';
            break;
        case '+':
            board[nr][nc] = 'W';
            break;
        default:
            return;
    }
    
    switch (board[r][c]) {
        case 'w':
            board[r][c] = '.';
            break;
        case 'W':
            board[r][c] = '+';
            break;
    }
    
    r = nr;
    c = nc;
}

void print_board() {
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

void init_testcase() {
    box_num = 0;
    box_cnt = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t = 1;
    while (true) {
        init_testcase();
        
        cin >> R >> C;
        if (R == 0 && C == 0) break;
        
        for (int i=0; i<R; i++) {
            cin >> s;
            for (int j=0; j<C; j++) {
                board[i][j] = s[j];
                
                if (board[i][j] == 'w' || board[i][j] == 'W') {
                    r = i;
                    c = j;
                }
                else if (board[i][j] == 'b') box_num++;
                else if (board[i][j] == 'B') {
                    box_num++;
                    box_cnt++;
                }
            }
        }
        
        cin >> m;
        for (int i=0; i<m.size(); i++) {
            int dir;
            switch (m[i]) {
                case 'U': dir = 0; break;
                case 'D': dir = 1; break;
                case 'R': dir = 2; break;
                case 'L': dir = 3; break;
            }
            
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            
            if (board[nr][nc] == 'b' || board[nr][nc] == 'B') move_box(nr, nc, dir);
            move_character(nr, nc);
            
            if (box_num == box_cnt) break;
        }
        
        cout << "Game " << t++ << ": ";
        if (box_num == box_cnt) cout << "complete";
        else cout << "incomplete";
        cout << "\n";
        print_board();
    }
    
    return 0;
}
