#include <iostream>
#include <deque>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int NMAX = 13, KMAX = 11;
const int WHITE = 0, RED = 1, BLUE = 2, R = 1, L = 2, U = 3, D = 4;

int N, K;
int color[NMAX][NMAX];
vector<int> board[NMAX][NMAX];
piii pieces[KMAX];

int dr[] = {0, 0, 0, -1, 1};
int dc[] = {0, 1, -1, 0, 0};

// void print_board() {
//     cout << "----------------------\n";
//     for (int i=1; i<=N; i++) {
//         for (int j=1; j<=N; j++) {
//             for (int k=0; k<4; k++) {
//                 if (k < board[i][j].size()) {
//                     cout << board[i][j][k];
//                     switch (pieces[board[i][j][k]].second) {
//                         case R: cout << "→"; break;
//                         case L: cout << "←"; break;
//                         case U: cout << "↑"; break;
//                         case D: cout << "↓"; break;
//                     }
//                 }
//                 else cout << "  ";
                
//                 cout << " ";
//             }
            
//             cout << "|";
//         }
        
//         cout << "\n";
//     }
//     cout << "----------------------\n";
// }

int pop_piece(int r, int c) {
    int ret = board[r][c].back();
    board[r][c].pop_back();
    
    return ret;
}

void put_piece(int r, int c, int p) {
    pieces[p].first = {r, c};
    board[r][c].push_back(p);
}

void reverse_direction(int p) {
    int d = pieces[p].second;
    
    int new_d;
    switch (d) {
        case R: new_d = L; break;
        case L: new_d = R; break;
        case U: new_d = D; break;
        case D: new_d = U; break;
    }
    
    pieces[p].second = new_d;
}

bool move_piece(int n) {
    deque<int> dq;
    int r = pieces[n].first.first;
    int c = pieces[n].first.second;
    int d = pieces[n].second;
    int next_r = r + dr[d];
    int next_c = c + dc[d];
    
    // 파란색이거나 체스판 벗어나는 경우 방향 반대로 변경
    if (next_r < 1 || next_r > N || next_c < 1 || next_c > N || color[next_r][next_c] == BLUE) {
        reverse_direction(n);

        d = pieces[n].second;
        next_r = r + dr[d];
        next_c = c + dc[d];
    }
    
    // 바꾼 후에도 파란색이거나 벗어나면 이동 안함
    if (next_r < 1 || next_r > N || next_c < 1 || next_c > N || color[next_r][next_c] == BLUE) return false;
    
    // n번말 위에 놓인 말들은 모두 함께 이동한다
    while (!board[r][c].empty()) {
        int p = pop_piece(r, c);
        dq.push_front(p);
        if (p == n) break;
    }
    
    // 이동
    while (!dq.empty()) {
        int p;
        
        if (color[next_r][next_c] == WHITE) {   // 흰색인 경우 순서대로 쌓기
            p = dq.front();
            dq.pop_front();
        }
        else {                                  // 빨간색인 경우 거꾸로 쌓기
            p = dq.back();
            dq.pop_back();
        }
        
        put_piece(next_r, next_c, p);
    }
    
    return board[next_r][next_c].size() >= 4;
}

int simulate() {
    int cnt = 1;
    
    while (true) {
        for (int i=1; i<=K; i++) {
            bool finish = move_piece(i);
            if (finish) return cnt;
        }
        
        cnt++;
        if (cnt > 1000) return -1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> color[i][j];
        }
    }
    
    int r, c, d;
    for (int i=1; i<=K; i++) {
        cin >> r >> c >> d;
        pieces[i] = {{r, c}, d};
        board[r][c].push_back(i);
    }
    
    cout << simulate();

    return 0;
}
