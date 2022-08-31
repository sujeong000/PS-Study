#include <iostream>

using namespace std;
typedef pair<int, int> pii;

int N;
int sand[500][500];

int dr[] = {0, 1, 0, -1};
int dc[] = {-1, 0, 1, 0};

int sdr[] = {-2, -1, -1, -1, 0, 1, 1, 1, 2};
int sdc[] = {0, -1, 0, 1, -2, -1, 0, 1, 0};
int sds[] = {2, 10, 7, 1, 5, 10, 7, 1, 2};

bool checkRange(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N;
}

int moveSand(int r, int c, int dir) {
    int outside = 0;
    int sandSum = 0;
    
    for (int i=0; i<9; i++) {
        int nr = r + sdr[i];
        int nc = c + sdc[i];
        int ns = sand[r][c] * sds[i] / 100;
        
        nr -= r;
        nc -= c;
        for (int d=0; d<dir; d++) {
            swap(nr, nc);
            nr *= -1;
        }
        nr += r;
        nc += c;
        
        if (!checkRange(nr, nc)) outside += ns;
        else sand[nr][nc] += ns;
        sandSum += ns;
    }
    
    int ar = r + dr[dir];
    int ac = c + dc[dir];
    
    sand[r][c] -= sandSum;
    if (!checkRange(ar, ac)) outside += sand[r][c];
    else sand[ar][ac] += sand[r][c];
    sand[r][c] = 0;
    
    return outside;
}

int simulate() {
    int ret = 0;
    int r = N/2, c = N/2;
    int len = 1;
    int cnt = 0;
    int dir = 0;
    
    while (r != 0 || c != 0) {
        r += dr[dir];
        c += dc[dir];
        
        ret += moveSand(r, c, dir);
        
        cnt++;
        if (cnt == len) {
            dir = (dir + 1) % 4;
            cnt = 0;
            if (dir % 2 == 0) len++;
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> sand[i][j];
        }
    }
    
    cout << simulate();

    return 0;
}
