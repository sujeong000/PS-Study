#include <iostream>
#include <cstring>

using namespace std;

const int LEFT = 0, RIGHT = 1;

int R, C;
string cave[100];
bool visit[100][100];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void throwStick(int h, int from) {
    for (int i=0; i<C; i++) {
        int c = from == LEFT ? i : C-i-1;
        if (cave[R-h][c] == 'x') {
            cave[R-h][c] = '.';
            break;
        }
    }
}

void DFS(int r, int c) {
    visit[r][c] = true;
    
    for (int i=0; i<4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
        if (cave[nr][nc] == '.' || visit[nr][nc]) continue;
        
        DFS(nr, nc);
    }
}

void checkFloating() {
    memset(visit, 0, sizeof(visit));
    
    for (int i=0; i<C; i++) {
        if (cave[R-1][i] == '.' || visit[R-1][i]) continue;
        DFS(R-1, i);
    }
}

void fall() {
    int minGap = R;
    
    for (int i=R-1; i>=0; i--) {
        for (int j=0; j<C; j++) {
            if (cave[i][j] == '.' || visit[i][j]) continue;
            
            minGap = min(minGap, R-i-1);
            for (int k=i+1; k<R; k++) {
                if (visit[k][j] && cave[k][j] == 'x') {
                    minGap = min(minGap, k-i-1);
                }
            }
        }
    }
    
    for (int i=R-1; i>=0; i--) {
        for (int j=0; j<C; j++) {
            if (cave[i][j] == '.' || visit[i][j]) continue;
            cave[i+minGap][j] = 'x';
            cave[i][j] = '.';
        }
    }
}

void simulate(int h, int from) {
    throwStick(h, from);
    checkFloating();
    fall();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> R >> C;
    for (int i=0; i<R; i++) cin >> cave[i];
    
    int N; cin >> N;
    for (int i=0; i<N; i++) {
        int h; cin >> h;
        simulate(h, i%2);
    }
    
    for (int i=0; i<R; i++) {
        cout << cave[i] << "\n";
    }

    return 0;
}
