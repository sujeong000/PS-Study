#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
const int INF = 987654321;

int N;
int A[20][20];
int board[20][20];
bool visit[20][20];

bool validate(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

void DFS(int r, int c) {
    board[r][c] = 5;
    
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    
    for (int i=0; i<4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (!validate(nr, nc) || board[nr][nc] != 0) continue;
        DFS(nr, nc);
    }
}

int simulate(int x, int y, int d1, int d2) {
    memset(board, 0, sizeof(board));
    memset(visit, 0, sizeof(visit));
    
    for (int i=0; i<=d1; i++) {
        if (!validate(x+i, y-i)) return INF;
        board[x+i][y-i] = 5;
    }
    
    for (int i=0; i<=d2; i++) {
        if (!validate(x+i, y+i)) return INF;
        board[x+i][y+i] = 5;
    }
    
    for (int i=0; i<=d2; i++) {
        if (!validate(x+d1+i, y-d1+i)) return INF;
        board[x+d1+i][y-d1+i] = 5;
    }
    
    for (int i=0; i<=d1; i++) {
        if (!validate(x+d2+i, y+d2-i)) return INF;
        board[x+d2+i][y+d2-i] = 5;
    }
    
    DFS(x+1, y);
    DFS(x+d2+d1-1, y+d2-d1);
    
    vector<int> pop_sum(6, 0);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (board[i][j] == 5) pop_sum[5] += A[i][j];
            else if (i < x+d1 && j <= y) {pop_sum[1] += A[i][j]; board[i][j]=1;}
            else if (i <= x+d2 && y < j) {pop_sum[2] += A[i][j];board[i][j]=2;}
            else if (x+d1 <= i && j < y-d1+d2) {pop_sum[3] += A[i][j];board[i][j]=3;}
            else {pop_sum[4] += A[i][j]; board[i][j]=4;}
        }
    }
    
    int max_pop = -1;
    int min_pop = INF;
    for (int i=1; i<=5; i++) {
        max_pop = max(max_pop, pop_sum[i]);
        min_pop = min(min_pop, pop_sum[i]);
    }
    
    return max_pop - min_pop;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> A[i][j];
        }
    }
    
    int ans = INF;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            for (int d1=1; d1<=N; d1++) {
                for (int d2=1; d2<=N; d2++) {
                    ans = min(ans, simulate(i, j, d1, d2));
                }
            }
        }
    }
    cout << ans;

    return 0;
}
