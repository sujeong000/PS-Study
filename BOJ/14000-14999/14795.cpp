#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

const int MAX = 100, BISHOP = 1, ROOK = 2, QUEEN = 3;
int T, N, M, Y, Z;
int original_board[MAX][MAX], board[MAX][MAX], bishops[MAX][MAX], rooks[MAX][MAX];
bool visit[2*MAX-1], matched[2*MAX-1];
int owner[2*MAX-1];

bool validate_rook_pos(int r, int c) {
    for (int i=0; i<N; i++) {
        if (rooks[r][i] || rooks[i][c]) return false;
    }
    
    return true;
}

void fill_rooks() {
    // 그리디하게 배치 가능, 항상 N개 놓아짐
    for (int r=0; r<N; r++) {
        for (int c=0; c<N; c++) {
            if (validate_rook_pos(r, c)) rooks[r][c] = true;
        }
    }
}

bool dfs(int idx) {
    // 기존에 놓인 비숍이면 변경할 수 없음.
    if (visit[idx] || matched[idx]) return false;
    
    visit[idx] = true;
    
    int start = abs(N-1-idx);   // idx번 왼쪽 대각선과 처음으로 만나는 오른쪽 대각선
    int len = N - start;        // idx번 왼쪽 대각선과 만나는 오른쪽 대각선 개수
    for (int i=start, cnt=0; cnt<len; i+=2, cnt++) {
        if (owner[i] == -1 || dfs(owner[i])) {
            owner[i] = idx;
            return true;
        }
    }
    
    return false;
}

// l번 왼쪽 대각선과 r번 오른쪽 대각선의 교차점
pair<int, int> intersect(int dl, int dr) {
    // r번 오른쪽 대각선이 l번 왼쪽 대각선과 몇 번째로 만나는지
    int order = (dr - abs(N-1-dl)) / 2;
    
    // l번 대각선의 시작 행,열
    int sr, sc;
    if (dl < N) {
        sr = 0;
        sc = dl;
    }
    else {
        sr = dl-N+1;
        sc = N-1;
    }
    
    return {sr+order, sc-order};
}

void bipartite_match() {
    // 대각선 당 비숍 개수는 최대 한 개 -이분매칭
    for (int i=0; i<2*N-1; i++) {
        memset(visit, 0, sizeof(visit));
        dfs(i);
    }
}

void fill_bishops() {
    // 기존에 올려진 비숍 처리
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (bishops[i][j]) {
                int idx = i*N+j;
                int l = idx/N + idx%N;
                int r = idx/N + N-1-idx%N;
                owner[r] = l;
                matched[l] = true;
            }
        }
    }
    
    bipartite_match();
    
    // 추가로 비숍 놓기
    for (int i=0; i<2*N-1; i++) {
        if (owner[i] != -1) {
            pair<int, int> pos = intersect(owner[i], i);
            int r = pos.first;
            int c = pos.second;
            bishops[r][c] = true;
        }
    }
}

void fill_board() {
    fill_rooks();
    fill_bishops();
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (bishops[i][j] && rooks[i][j]) {
                board[i][j] = QUEEN;
                Y += 2;
            }
            else if (bishops[i][j]) {
                board[i][j] = BISHOP;
                Y++;
            }
            else if (rooks[i][j]) {
                board[i][j] = ROOK;
                Y++;
            }
            
            if (original_board[i][j] != board[i][j]) Z++;
        }
    }
}

void init_testcase() {
    Y = 0;
    Z = 0;
    memset(rooks, 0, sizeof(rooks));
    memset(bishops, 0, sizeof(bishops));
    memset(owner, -1, sizeof(owner));
    memset(original_board, 0, sizeof(original_board));
    memset(board, 0, sizeof(board));
    memset(matched, 0, sizeof(matched));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    
    for (int t=1; t<=T; t++) {
        init_testcase();
        
        cin >> N >> M;
        
        char k;
        int R, C;
        for (int i=0; i<M; i++) {
            cin >> k >> R >> C;
            R--; C--;
            
            // +끼리 같은 대각선에 있을 수 없다 = 비숍
            // x끼리 같은 줄에 있을 수 없다 = 룩
            // +와 o는 같은 대각선에 있을 수 없다.
            // x와 o는 같은 줄에 있을 수 없다.
            // o = 퀸 = 룩 + 비숍
            // 룩 배치와 비숍 배치는 독립적인 문제로 분할할 수 있다.
            switch (k) {
                case '+':
                    original_board[R][C] = BISHOP;
                    bishops[R][C] = true;
                    break;
                case 'x':
                    original_board[R][C] = ROOK;
                    rooks[R][C] = true;
                    break;
                case 'o':
                    original_board[R][C] = QUEEN;
                    bishops[R][C] = true;
                    rooks[R][C] = true;
                    break;
                default:
                    break;
            }
        }
        
        fill_board();
        
        cout << "Case #" << t << ": " << Y << " " << Z << "\n";
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (original_board[i][j] == board[i][j]) continue;
                
                switch (board[i][j]) {
                    case QUEEN: cout << "o"; break;
                    case BISHOP: cout << "+"; break;
                    case ROOK: cout << "x"; break;
                    default: break;
                }
                cout << " " << i+1 << " " << j+1 << "\n";
            }
        }
    }

    return 0;
}
