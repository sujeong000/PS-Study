#include <iostream>
#include <string.h>

using namespace std;

const int MAX_N = 101;
typedef long long ll;

int N;
int board[MAX_N][MAX_N];
ll cache[MAX_N][MAX_N];

ll dp(int r, int c) {
    if (r == N-1 && c == N-1) return 1;
    
    ll& ret = cache[r][c];
    if (ret != -1) return ret;
    
    ret = 0;
    if (board[r][c] == 0) return ret;
    
    int nr = r + board[r][c];
    int nc = c + board[r][c];
    if (nr < N) ret += dp(nr, c);
    if (nc < N) ret += dp(r, nc);
    
    return ret;
}

int main() {
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cache[i][j] = -1;
            cin >> board[i][j];
        }
    }
    
    cout << dp(0, 0);
    
    return 0;
}
