#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 10;
const int U = 0, D = 1, L = 2, R = 3;
const int RED = 100, BLUE = 200;

struct Marble {
    int r, c;
    char color;
};

int N, M;
Marble H;
char board[MAX][MAX];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool operator== (const Marble& lhs, const Marble& rhs) {
    return lhs.r == rhs.r && lhs.c == rhs.c;
}

bool fallIntoHole(Marble m) {
    return m == H;
}

Marble move(int dir, Marble m) {
    Marble ret = m;
    
    while (!fallIntoHole(ret)) {
        int nr = ret.r + dr[dir];
        int nc = ret.c + dc[dir];
        
        if (board[nr][nc] == '#' || board[nr][nc] == 'R' || board[nr][nc] == 'B') break;
        
        ret.r = nr;
        ret.c = nc;
    }
    
    board[m.r][m.c] = '.';
    if (!fallIntoHole(ret)) board[ret.r][ret.c] = m.color;
    
    return ret;
}

int firstMove(int dir, Marble red, Marble blue) {
    switch (dir) {
        case U: return red.r <= blue.r ? RED : BLUE;
        case D: return red.r >= blue.r ? RED : BLUE;
        case L: return red.c <= blue.c ? RED : BLUE;
        case R: return red.c >= blue.c ? RED : BLUE;
        default: return 0;
    }
}

bool DFS(int depth, Marble red, Marble blue) {
    if (depth > 10) return false;
    if (fallIntoHole(blue)) return false;
    if (fallIntoHole(red)) return true;
    
    char temp[MAX][MAX];
    copy(&board[0][0], &board[0][0]+MAX*MAX, &temp[0][0]);
    
    for (int i=0; i<4; i++) {
        Marble newRed, newBlue;
        
        if (firstMove(i, red, blue) == RED) {
            newRed = move(i, red);
            newBlue = move(i, blue);
        }
        else {
            newBlue = move(i, blue);
            newRed = move(i, red);
        }
        
        if (red == newRed && blue == newBlue) continue;
        if (DFS(depth+1, newRed, newBlue)) return true;
        
        copy(&temp[0][0], &temp[0][0]+MAX*MAX, &board[0][0]);
    }
    
    return false;
}

int main()
{
    cin >> N >> M;
    
    Marble red, blue;
    string temp;
    
    for (int i=0; i<N; i++) {
        cin >> temp;
        
        for (int j=0; j<M; j++) {
            board[i][j] = temp[j];
            
            if (temp[j] == 'R') red = {i, j, 'R'};
            else if (temp[j] == 'B') blue = {i, j, 'B'};
            else if (temp[j] == 'O') H = {i, j, 'O'};
        }
    }
    
    if (DFS(0, red, blue)) cout << 1;
    else cout << 0;

    return 0;
}
