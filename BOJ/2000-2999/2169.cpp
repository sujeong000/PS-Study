#include <iostream>
#include <string.h>

using namespace std;

const int INF = 987654321;
const int UP = 0, LEFT = 1, RIGHT = 2;

int N, M;
int board[1001][1001], cache[1001][1001][3];
int psum[1001]; // 마지막 줄 누적합

// dp(r, c): 이전 칸이 before이고 현재 (r, c)일 때, (N, M)으로 가면서 얻을 수 있는 가치의 최대 합
int dp(int r, int c, int before) {
    if (r == N) return psum[M] - psum[c-1];
    
    int& ret = cache[r][c][before];
    if (ret != -1) return ret;
    
    ret = board[r][c] + dp(r+1, c, UP); // 아래로 가는 경우
    if (before != LEFT && c>1) {        // 왼쪽으로 가는 경우
        ret = max(ret, board[r][c]+dp(r, c-1, RIGHT));
    }
    if (before != RIGHT && c<M) {        // 오른쪽으로 가는 경우
        ret = max(ret, board[r][c]+dp(r, c+1, LEFT));
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            cin >> board[i][j];
        }
    }
    for (int i=1; i<=M; i++) {
        psum[i] = psum[i-1] + board[N][i];
    }
    
    cout << dp(1, 1, UP);

    return 0;
}
