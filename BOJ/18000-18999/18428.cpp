#include <iostream>

using namespace std;

int N;
char board[6][6];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool check() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (board[i][j] != 'T') continue;
            
            for (int k=0; k<4; k++) {
                int r = i, c = j;
                while (r >= 0 && r < N && c >= 0 && c < N && board[r][c] != 'O') {
                    r += dr[k];
                    c += dc[k];
                    
                    if (board[r][c] == 'S') return false;
                }
            }
        }
    }
    
    return true;
}

bool dfs(int cnt) {
    if (cnt == 3) return check();
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (board[i][j] == 'X') {
                board[i][j] = 'O';
                if (dfs(cnt+1)) return true;
                board[i][j] = 'X';
            }
        }
    }
    
    return false;
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
    
    if (dfs(0)) cout << "YES";
    else cout << "NO";

    return 0;
}
