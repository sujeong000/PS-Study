#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int N, M;
char board[3000][3000];
int r_combo[3000][3000], d_combo[3000][3000];   // (i,j)부터 우,하방향으로 몇개까지 체크무늬가 유지되는지
int cache[3000][3000];

// dp(r, c) = (r, c)를 왼쪽 꼭짓점으로 하는 체스판의 최대 크기
int dp(int r, int c) {
    if (r == N-1 || c == M-1) return 1;

    int& ret = cache[r][c];
    if (ret != -1) return ret;
    
    if (board[r][c] != board[r+1][c+1]) ret = 1;
    else ret = min(min(r_combo[r][c], d_combo[r][c]), 1 + dp(r+1, c+1));
    
    return ret;
}

void calc_combo() {
    for(int i=N-1; i>=0; i--) {
        for(int j=M-1; j>=0; j--) {
            if (j == M-1 || board[i][j] == board[i][j+1]) r_combo[i][j] = 1;
            else r_combo[i][j] = r_combo[i][j+1] + 1;
            
            if (i == N-1 || board[i][j] == board[i+1][j]) d_combo[i][j] = 1;
            else d_combo[i][j] = d_combo[i+1][j] + 1;
        }
    }
}

long long count_case() {
    long long sum = 0;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            sum += dp(i, j);
        }
    }
    
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(cache, -1, sizeof(cache));

    cin >> N >> M;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> board[i][j];
        }
    }
    
    calc_combo();
    
    cout << count_case();

    return 0;
}
