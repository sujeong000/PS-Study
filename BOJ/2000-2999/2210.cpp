#include <iostream>
#include <unordered_set>

using namespace std;

int board[5][5];
unordered_set<int> st;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void DFS(int n, int r, int c, int curr) {
    if (n == 6) {
        st.insert(curr);
        return;
    }
    
    for (int i=0; i<4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;
        
        DFS(n+1, nr, nc, curr*10 + board[nr][nc]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            cin >> board[i][j];
        }
    }
    
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            DFS(1, i, j, board[i][j]);
        }
    }
    
    cout << st.size();

    return 0;
}
