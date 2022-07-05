#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N, M;
int board[50][50];
int explosionCnt[4];

struct MarbleCombo {
    int type;
    int cnt;
};

void pushBackMarbles(deque<MarbleCombo>& marbles, MarbleCombo mc) {
    if (marbles.empty() || marbles.back().type != mc.type) {
        marbles.push_back(mc);
    }
    else {
        marbles.back().cnt += mc.cnt;
    }
}

void destroyMarbles(int d, int s) {
    int dr[] = {0, -1, 1, 0, 0};
    int dc[] = {0, 0, 0, -1, 1};
    
    for (int i=1; i<=s; i++) {
        board[(N+1)/2 + i*dr[d]][(N+1)/2 + i*dc[d]] = 0;
    }
}

// emptyBoard(): 1번 칸부터 오름차순으로 덱으로 만들어 반환
deque<MarbleCombo> emptyBoard() {
    deque<MarbleCombo> ret;
    
    int dr[] = {0, 1, 0, -1};
    int dc[] = {-1, 0, 1, 0};
    
    int r = (N+1)/2;
    int c = (N+1)/2;
    int d = 0;
    int w = 1;
    int cnt = 0;
    
    while (true) {
        r += dr[d]; 
        c += dc[d];
        cnt++;
        
        if (board[r][c] != 0) {
            pushBackMarbles(ret, {board[r][c], 1});
            board[r][c] = 0;
        }
        
        if (cnt == w) {
            d = (d + 1) % 4;
            cnt = 0;
            if (d % 2 == 0) w++;
        }
        
        if (r == 1 && c == 1) break;
    }
    
    return ret;
}

// explodeMarbles(marbles): 4개 이상 연속된 구슬이 없을 때까지 연쇄 폭발
void explodeMarbles(deque<MarbleCombo>& marbles) {
    deque<MarbleCombo> temp;
    bool explode = true;
    
    while (explode) {
        explode = false;
        
        while (!marbles.empty()) {
            auto mc = marbles.front(); marbles.pop_front();
            
            if (mc.cnt < 4) {
                pushBackMarbles(temp, mc);
            }
            else {
                explosionCnt[mc.type] += mc.cnt;
                explode = true;
            }
        }
        
        while (!temp.empty()) {
            marbles.push_back(temp.front());
            temp.pop_front();
        }
    }
}

// fillBoard(marbles): 모든 작업이 끝난 구슬들을 다시 보드에 채우기
void fillBoard(deque<int>& marbles) {
    int dr[] = {0, 1, 0, -1};
    int dc[] = {-1, 0, 1, 0};
    
    int r = (N+1)/2;
    int c = (N+1)/2;
    int d = 0;
    int w = 1;
    int cnt = 0;
    
    while (!marbles.empty()) {
        r += dr[d]; 
        c += dc[d];
        
        board[r][c] = marbles.front(); marbles.pop_front();

        if (++cnt == w) {
            d = (d + 1) % 4;
            cnt = 0;
            if (d % 2 == 0) w++;
        }
        
        if (r == 1 && c == 1) break;
    }
}

void blizzard(int d, int s) {
    destroyMarbles(d, s);
    
    auto marbles = emptyBoard();
    
    explodeMarbles(marbles);
    
    deque<int> newMarbles;
    for (auto mc: marbles) {
        newMarbles.push_back(mc.cnt);
        newMarbles.push_back(mc.type);
    }
    fillBoard(newMarbles);
}

int main()
{
    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> board[i][j];
        }
    }
    
    for (int i=0; i<M; i++) {
        int d, s;
        cin >> d >> s;
        
        blizzard(d, s);
    }
    
    cout << 1*explosionCnt[1] + 2*explosionCnt[2] + 3*explosionCnt[3];

    return 0;
}
