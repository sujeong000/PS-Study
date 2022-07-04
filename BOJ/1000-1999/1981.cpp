#include <iostream>
#include <cstring>

using namespace std;

const int INF = 987654321;

int N;
int board[100][100];
bool visit[100][100];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

// DFS(r, c, minVal, maxVal)
//: 현재 (r, c)일 때, minVal이상 maxVal 이하인 칸들만 거쳐서 (N-1, N-1)에 도착가능한가
bool DFS(int r, int c, int minVal, int maxVal) {
    if (board[r][c] < minVal || board[r][c] > maxVal) return false;
    if (r == N-1 && c == N-1) return true;
    visit[r][c] = true;
    
    for (int i=0; i<4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
        if (visit[nr][nc]) continue;
        
        if (DFS(nr, nc, minVal, maxVal)) return true;
    }
    
    return false;
}

bool decision(int gap) {
    for (int i=0; i<=200-gap; i++) {
        memset(visit, 0, sizeof(visit));
        if (DFS(0, 0, i, i+gap)) return true;    
    }
    
    return false;
}

int optimize() {
    int lo = -1, hi = 200;
    
    while (lo+1 < hi) {
        int mid = (lo+hi)/2;
        if (decision(mid)) hi = mid;
        else lo = mid;
    }
    
    return hi;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> board[i][j];
        }
    }
    
    cout << optimize();

    return 0;
}
