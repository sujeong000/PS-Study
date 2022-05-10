#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
const int SHARK = 0, EMPTY = -2, MAX = 17, N = 4, OUT = -1;

int board[N][N], temp_board[100][N][N], temp2_board[100][N][N];
int dir[MAX], temp_dir[100][MAX], temp2_dir[100][MAX];
pii pos[MAX], temp_pos[100][MAX], temp2_pos[100][MAX];
bool eaten[MAX], temp_eaten[100][MAX], temp2_eaten[100][MAX];

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, -1, -1, -1, 0, 1, 1, 1};

string c[] = {"↑", "↖", "←", "↙", "↓", "↘", "→", "↗"};

void print_board() {
    cout << "---------------------\n";
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (board[i][j] == EMPTY) cout << "  ";
            else cout << board[i][j] << c[dir[board[i][j]]];
            cout << " ";
        }
        cout << "\n";
    }
    cout << "---------------------\n";
}

void copy_origin_to_temp(int depth) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            temp_board[depth][i][j] = board[i][j];
        }
    }
    for (int i=0; i<MAX; i++){
        temp_dir[depth][i] = dir[i];
        temp_eaten[depth][i] = eaten[i];
        temp_pos[depth][i] = pos[i];
    }
}

void copy_origin_to_temp2(int depth) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            temp2_board[depth][i][j] = board[i][j];
        }
    }
    for (int i=0; i<MAX; i++){
        temp2_dir[depth][i] = dir[i];
        temp2_eaten[depth][i] = eaten[i];
        temp2_pos[depth][i] = pos[i];
    }
}

void copy_temp_to_origin(int depth) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            board[i][j] = temp_board[depth][i][j];
        }
    }
    for (int i=0; i<MAX; i++){
        dir[i] = temp_dir[depth][i];
        eaten[i] = temp_eaten[depth][i];
        pos[i] = temp_pos[depth][i];
    }
}

void copy_temp2_to_origin(int depth) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            board[i][j] = temp2_board[depth][i][j];
        }
    }
    for (int i=0; i<MAX; i++){
        dir[i] = temp2_dir[depth][i];
        eaten[i] = temp2_eaten[depth][i];
        pos[i] = temp2_pos[depth][i];
    }
}

void move_fish() {
    for (int i=1; i<MAX; i++) {
        if (eaten[i]) continue;
        
        int r = pos[i].first;
        int c = pos[i].second;
        int next_r = r + dr[dir[i]];
        int next_c = c + dc[dir[i]];
        
        // 이동가능할 때까지 회전
        while (next_r < 0 || next_r > 3 || next_c < 0 || next_c > 3 || board[next_r][next_c] == SHARK) {
            dir[i] = (dir[i] + 1) % 8;
            next_r = r + dr[dir[i]];
            next_c = c + dc[dir[i]];
        }
        
        // 물고기 이동
        if (board[next_r][next_c] == EMPTY) {
            board[r][c] = EMPTY;
            board[next_r][next_c] = i;
            pos[i] = {next_r, next_c};
        }
        else {  // 다른 물고기가 있는 칸이면 스왑
            swap(pos[i], pos[board[next_r][next_c]]);
            swap(board[r][c], board[next_r][next_c]);
        }
    }
}

int move_shark(int n) {
    int r = pos[SHARK].first;
    int c = pos[SHARK].second;
    int next_r = r + n * dr[dir[SHARK]];
    int next_c = c + n * dc[dir[SHARK]];
    
    if (next_r < 0 || next_r > 3 || next_c < 0 || next_c > 3) return OUT;
    if (board[next_r][next_c] == EMPTY) return EMPTY;
    
    int fish = board[next_r][next_c];
    eaten[fish] = true;
    dir[SHARK] = dir[fish];
    pos[SHARK] = {next_r, next_c};
    board[next_r][next_c] = SHARK;
    board[r][c] = EMPTY;
    
    return fish;
}

int backtrack(int depth) {
    int ret = 0;
    
    copy_origin_to_temp(depth);
    move_fish();
    copy_origin_to_temp2(depth);
    
    int n = 1;
    while (true) {
        int score = move_shark(n++);
        if (score == EMPTY) continue;
        if (score == OUT) break;
        
        ret = max(ret, score+backtrack(depth+1));
        copy_temp2_to_origin(depth);
    }
    
    copy_temp_to_origin(depth);
    
    return ret;
}

int eat_first_fish() {
    int first_fish = board[0][0];
    eaten[first_fish] = true;
    dir[SHARK] = dir[first_fish];
    board[0][0] = SHARK;
    
    return first_fish;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int a, b;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            cin >> a >> b;
            board[i][j] = a;
            dir[a] = b-1;
            pos[a] = {i, j};
        }
    }
    
    cout << eat_first_fish() + backtrack(0);

    return 0;
}
