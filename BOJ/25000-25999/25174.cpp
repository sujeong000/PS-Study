#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1005, INF = 100000000;

struct Cat {
    int x, y, z;
    int nx, ny;
};

int N, board[MAX][MAX], psum[MAX][MAX];
Cat cats[MAX];

bool cmp_x(Cat lhs, Cat rhs) {
    return lhs.x < rhs.x;
}

bool cmp_y(Cat lhs, Cat rhs) {
    return lhs.y < rhs.y;
}

int min(int a, int b, int c, int d) {
    return min(min(a, b), min(c, d));
}

int max(int a, int b, int c, int d) {
    return max(max(a, b), max(c, d));
}

// 지도에서 (r1, c1)부터 (r2, c2)까지의 Z합
int sum(int r1, int c1, int r2, int c2) {
    int ret = psum[r2][c2];
    
    if (c1 != 0) ret -= psum[r2][c1-1];
    if (r1 != 0) ret -= psum[r1-1][c2];
    if (c1 != 0 && r1 != 0) ret += psum[r1-1][c1-1];
    
    return ret;
}

// x좌표 압축
void calc_nx() {
    sort(cats, cats+N, cmp_x);
    
    int cnt = 1;
    for (int i=0; i<N; i++) {
        if (i != 0 && cats[i].x != cats[i-1].x) cnt++;
        cats[i].nx = cnt;
    }
}

// y좌표 압축
void calc_ny() {
    sort(cats, cats+N, cmp_y);
    
    int cnt = 1;
    for (int i=0; i<N; i++) {
        if (i != 0 && cats[i].y != cats[i-1].y) cnt++;
        cats[i].ny = cnt;
    }
}

// 압축한 좌표로 다시 지도를 그림
void fill_board() {
    for (int i=0; i<N; i++) {
        int x = cats[i].nx;
        int y = cats[i].ny;
        board[x][y] = cats[i].z;
    }
}

void calc_psum() {
    for (int i=1; i<MAX; i++) {
        for (int j=1; j<MAX; j++) {
            psum[i][j] = psum[i][j-1] + psum[i-1][j] - psum[i-1][j-1] + board[i][j];
        }
    }
}

// 2사분면의 오른쪽 꼭짓점이 x, y이도록 사분면을 나눴을 때 E값
int calc_E(int x, int y) {
    int A = sum(0, 0, x, y);                // 2사분면
    int B = sum(x+1, 0, MAX-1, y);          // 1사분면
    int C = sum(0, y+1, x, MAX-1);          // 3사분면
    int D = sum(x+1, y+1, MAX-1, MAX-1);    // 4사분면

    return max(A, B, C, D) - min(A, B, C, D);
}

int find_min_E() {
    int ret = INF;
    
    for (int i=0; i<MAX; i++) {
        for (int j=0; j<MAX; j++) {
            ret = min(ret, calc_E(i, j));
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    int x, y, z;
    for (int i=0; i<N; i++) {
        cin >> x >> y >> z;
        cats[i] = {x, y, z};
    }
    
    calc_nx();
    calc_ny();
    fill_board();
    calc_psum();
    
    cout << find_min_E();

    return 0;
}
