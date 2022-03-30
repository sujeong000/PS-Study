#include <iostream>
#include <string.h>

using namespace std;

const int INF = 987654321;
int N, M;
char board[50][50];
bool visit[50][50], finished[50][50];
int cache[50][50];

int dp(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= M) return 0;
    if (board[r][c] == 'H') return 0;
    
    int& ret = cache[r][c];
    if (ret != -1) return ret;
    
    ret = 0;
    int d = board[r][c] - '0';
    int dr[4] = {-d, d, 0, 0};
    int dc[4] = {0, 0, -d, d};
    for (int i=0; i<4; i++) {
        int next_r = r + dr[i];
        int next_c = c + dc[i];
        
        ret = max(ret, 1 + dp(next_r, next_c));
    }
    
    return ret;
}

bool check_cycle(int r, int c) {
    visit[r][c] = true;
    
    int d = board[r][c] - '0';
    int dr[4] = {-d, d, 0, 0};
    int dc[4] = {0, 0, -d, d};
    for (int i=0; i<4; i++) {
        int next_r = r + dr[i];
        int next_c = c + dc[i];
        
        if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= M) continue;
        if (board[next_r][next_c] == 'H') continue;
        
        if (!visit[next_r][next_c]) {
            if (check_cycle(next_r, next_c)) return true;
        }
        else if (!finished[next_r][next_c]) return true;
    }
    
    finished[r][c] = true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N >> M;
    
    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        
        for (int j=0; j<M; j++) {
            board[i][j] = s[j];
        }
    }
    
    if (check_cycle(0, 0)) cout << -1;
    else cout << dp(0, 0);

    return 0;
}
