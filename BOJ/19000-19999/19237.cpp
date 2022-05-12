#include <iostream>

using namespace std;

typedef pair<int, int> pii;
const int U = 0, L = 1, D = 2, R = 3, EMPTY = 0;

struct Board {
    int shark = 0;
    int smell_owner = 0;
    int smell_duration = 0;
};

struct Shark {
    int idx;
    int r;
    int c;
    int d;
    bool out = false;
    int priority[4][4];
};

int N, M, K;
Board board[20][20], copied_board[20][20];
Shark sharks[401];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
// string cc[] = {"↑", "↓", "←", "→"};

// void print_board() {
//     cout << "=====================\n";
//     for (int i=0; i<N; i++) {
//         for (int j=0; j<N; j++) {
//             if (board[i][j].smell_owner == EMPTY) cout << "   ";
//             else cout << board[i][j].smell_owner << "," << board[i][j].smell_duration;
            
//             if (board[i][j].shark == EMPTY) cout << "(   )";
//             else cout << "(" << board[i][j].shark << "," << cc[sharks[board[i][j].shark].d] << ")";
            
//             cout << " | ";
//         }
//         cout << "\n";
//     }
// }

void copy_board() {
    for (int i=0; i<20; i++) {
        for (int j=0; j<20; j++) {
            copied_board[i][j] = board[i][j];
        }
    }
}

pii calc_next_pos(int r, int c, int d) {
    return {r + dr[d], c + dc[d]};
}

bool validate_pos(pii pos) {
    int r = pos.first;
    int c = pos.second;
    return r >= 0 && r < N && c >= 0 && c < N;
}

bool put_shark(int r, int c, int d, Shark& s) {
    bool ret = board[r][c].shark != EMPTY;
    
    board[s.r][s.c].shark = EMPTY;
    if (board[r][c].shark == EMPTY || board[r][c].shark > s.idx) {
        sharks[board[r][c].shark].out = true;
        board[r][c].shark = s.idx;
        board[r][c].smell_owner = s.idx;
        board[r][c].smell_duration = K+1;
        s.r = r;
        s.c = c;
        s.d = d;
    }
    else s.out = true;
    
    return ret;
}

bool move_shark(Shark& s) {
    for (int i=0; i<2; i++) {
        for (auto dir : s.priority[s.d]) {
            pii next_pos = calc_next_pos(s.r, s.c, dir);
            if (!validate_pos(next_pos)) continue;
            
            int nr = next_pos.first;
            int nc = next_pos.second;
            switch (i) {
                case 0:
                    if (copied_board[nr][nc].smell_owner == EMPTY) return put_shark(nr, nc, dir, s);
                    break;
                case 1:
                    if (copied_board[nr][nc].smell_owner == s.idx) return put_shark(nr, nc, dir, s);
                    break;
            }
        }
    }
    
    return false;
}

int move_sharks() {
    int ret = 0;
    
    for (int i=1; i<=M; i++) {
        if (sharks[i].out) continue;
        if (move_shark(sharks[i])) ret++;
    }
    
    return ret;
}

void smell_count_down() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            board[i][j].smell_duration--;
            if (board[i][j].smell_duration == 0) board[i][j].smell_owner = EMPTY;
        }
    }
}

int simulate() {
    int shark_cnt = M;
    int turn = 0;
    
    while (shark_cnt > 1) {
        copy_board();
        
        shark_cnt -= move_sharks();
        smell_count_down();
        
        turn++;
        if (turn > 1000) return -1;
    }
    
    return turn;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> K;
    
    int s;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> s;
            
            board[i][j].shark = s;
            board[i][j].smell_owner = s;
            board[i][j].smell_duration = K;
            sharks[s].r = i;
            sharks[s].c = j;
        }
    }
    
    int dir;
    for (int s=1; s<=M; s++) {
        cin >> dir;
        sharks[s].d = dir - 1;
    }
    
    for (int s=1; s<=M; s++) {
        sharks[s].idx = s;
        
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                cin >> dir;
                sharks[s].priority[i][j] = dir - 1;
            }
        }
    }
    
    cout << simulate();

    return 0;
}
