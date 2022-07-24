#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
const int ENEMY = 1;
const pii NO_TARGET = {-1, -1};

int N, M, D;
int board[15][15];
bool isDead[15][15];

// calcTarget(r, c): r, c 위치에 있는 궁수의 타겟 계산
pii calcTarget(int r, int c) {
    for (int d = 1; d <= D; d++) {
        for (int dc = -(d-1); dc <= (d-1); dc++) {
            int dr = -(d - abs(dc));
            int er = r + dr;
            int ec = c + dc;
            if (er < 0 || er >= N || ec < 0 || ec >= M) continue;
            
            if (board[er][ec] == ENEMY && !isDead[er][ec]) {
                return {er, ec};
            }
        }
    }
    
    return NO_TARGET;
}

int simulate(int archer1, int archer2, int archer3) {
    int killCnt = 0;
    vector<int> archers = {archer1, archer2, archer3};
    
    memset(isDead, 0, sizeof(isDead));
    
    // 적을 한 칸 내리는 대신 궁수를 한 칸 올림
    for (int i=N; i>0; i--) {
        vector<pii> targets;
        
        for (auto archer: archers) {
            targets.push_back(calcTarget(i, archer)); 
        }
        
        // 적 모아서 한번에 처리
        for (auto target: targets) {
            if (target == NO_TARGET) continue;
            
            int r = target.first;
            int c = target.second;
            
            if (!isDead[r][c]) killCnt++;
            isDead[r][c] = true;
        }
    }
    
    return killCnt;
}

int solution(){
    int maxKill = 0;
    
    for (int i=0; i<M-2; i++) {
        for (int j=i+1; j<M-1; j++) {
            for (int k=j+1; k<M; k++) {
                maxKill = max(maxKill, simulate(i, j, k));
            }
        }
    }
    
    return maxKill;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> D;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> board[i][j];
        }
    }
    
    cout << solution();

    return 0;
}
