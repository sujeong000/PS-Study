#include <iostream>

using namespace std;
const int EMPTY = 0, WALL = 1;

int N, M;
int R, C, D;
bool board[50][50];
bool cleaned[50][50];

// 북동남서
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

bool validatePos(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M && board[r][c] == EMPTY;
}

bool checkCleanable(int r, int c) {
    return validatePos(r, c) && !cleaned[r][c];
}

bool findSpaceToClean(int r, int c, int d) {
    for (int i=0; i<4; i++) {
        int nr = r + dr[(d+i)%4];
        int nc = c + dc[(d+i)%4];
        if (checkCleanable(nr, nc)) return true;
    }
    
    return false;
}

int simulate() {
    int ret = 0;
    
    while (true) {
        // 1. 현재 위치를 청소한다.
        cleaned[R][C] = true;
        ret++;
        
        // 2. 왼쪽부터 차례로 탐색한다.
        while (true) {
            if (!findSpaceToClean(R, C, D)) {
                // 2-3. 네 방향 모두 청소할 수 없다면 후진
                int NR = R + dr[(D+2)%4];
                int NC = C + dc[(D+2)%4];
                R = NR;
                C = NC;
                
                // 2-4. 후진도 못한다면 종료
                if (!validatePos(NR, NC)) return ret;
            }
            else {
                int LD = (D-1+4) % 4;
                int lr = R + dr[LD];
                int lc = C + dc[LD];
                
                if (validatePos(lr, lc) && !cleaned[lr][lc]) {
                    // 2-1. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 
                    D = LD;             // 그 방향으로 회전한 다음 
                    R = lr; C = lc;     // 한 칸을 전진하고
                    break;              // 1번부터 진행한다.
                }
                else {
                    // 2-2. 왼쪽 방향에 청소할 공간이 없다면,
                    D = LD;     // 그 방향으로 회전하고
                    continue;   // 2번으로 돌아간다.
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    cin >> R >> C >> D;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> board[i][j];
        }
    }
    
    cout << simulate();

    return 0;
}
