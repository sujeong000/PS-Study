#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
typedef pair<int, int> pii;
const int UP = 0, LEFT = 1, DOWN = 2, RIGHT = 3;

int R, C, SR, SC;
string board[25];
vector<bool> not_connected[25][25];

char blocks[] = {'|', '-', '+', '1', '2', '3', '4'};
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, -1, 0, 1};
vector<bool> adjs[7] =
{
  {1, 0, 1, 0},
  {0, 1, 0, 1},
  {1, 1, 1, 1},
  {0, 0, 1, 1},
  {1, 0, 0, 1},
  {1, 1, 0, 0},
  {0, 1, 1, 0}
};

vector<bool> getAdjacent(int r, int c) {
    switch (board[r][c]) {
        case '|': return adjs[0];
        case '-': return adjs[1];
        case '+': return adjs[2];
        case '1': return adjs[3];
        case '2': return adjs[4];
        case '3': return adjs[5];
        case '4': return adjs[6];
    }
    
    return {};
}

void checkConnected(int r, int c) {
    auto adjs = getAdjacent(r, c);
    
    for (int i=0; i<4; i++) {
        if (!adjs[i]) continue;
        
        int adjr = r + dr[i];
        int adjc = c + dc[i];
        if (adjr < 0 || adjr >= R || adjc < 0 || adjc >= C) continue;
    
        if (board[adjr][adjc] == '.') not_connected[adjr][adjc][(i+2)%4] = true;
    }
}

char calcBlock(int r, int c) {
    for (int i=0; i<7; i++) {
        if (not_connected[r][c] == adjs[i]) return blocks[i];
    }
    
    return '?';
}

void solution() {
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (board[i][j] == '.') continue;
            if (board[i][j] == 'M' || board[i][j] == 'Z') continue;
            checkConnected(i, j);
        }
    }
    
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            for (int k=0; k<4; k++) {
                if (not_connected[i][j][k]) {
                    cout << i+1 << " " << j+1 << " " << calcBlock(i, j);
                    return;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int i=0; i<25; i++) {
        for (int j=0; j<25; j++) {
            not_connected[i][j].resize(4);
        }
    }
    
    cin >> R >> C;
    for (int i=0; i<R; i++) {
        cin >> board[i];
        for (int j=0; j<C; j++) {
            if (board[i][j] == 'M') {
                SR = i;
                SC = j;
            }
        }
    }
    
    solution();

    return 0;
}
