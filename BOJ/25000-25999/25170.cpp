#include <iostream>
#include <string.h>

using namespace std;

const int MAX = 51, INF = 987654321;

int N, M, T;
int work[MAX][MAX], cost[MAX][MAX];
int cache[501][MAX][MAX];

int dr[] = {1, 1, 0};
int dc[] = {0, 1, 1};

int dp(int t, int r, int c) {
    if (r == N-1 && c == M-1) return 0;
    if (t == 0) return -INF;
    
    int& ret = cache[t][r][c];
    if (ret != -1) return ret;
    
    ret = -INF;
    for (int i=0; i<3; i++) {
        int next_r = r + dr[i];
        int next_c = c + dc[i];
        if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= M) continue;
        
        ret = max(ret, dp(t-1, next_r, next_c));
        if (cost[r][c] <= t-1) ret = max(ret, work[r][c] + dp(t-1-cost[r][c], next_r, next_c));
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N >> M >> T;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> work[i][j];
        }
    }
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> cost[i][j];
        }
    }
    
    cout << dp(T, 0, 0);

    return 0;
}
