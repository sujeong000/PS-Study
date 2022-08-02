#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int N, M;
int board[50][50];
int visit[50][50];
int roomSize[2501];

int dr[] = {0, -1, 0, 1};
int dc[] = {-1, 0, 1, 0};

int DFS(int r, int c, int mark) {
    if (visit[r][c]) return 0;
    
    int ret = 1;
    visit[r][c] = mark;
    
    for (int i=0; i<4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
        if ((board[r][c] & (1 << i)) != 0) continue;
        
        ret += DFS(nr, nc, mark);
    }
    
    return ret;
}

piii solution() {
    int cnt = 0;
    int widestRoom = 0;
    int widestRoomWhenRemoveWall = 0;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (!visit[i][j]) {
                cnt++;
                roomSize[cnt] = DFS(i, j, cnt);
                widestRoom = max(widestRoom, roomSize[cnt]);
            }
        }
    }
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            for (int k=0; k<4; k++) {
                int nr = i + dr[k];0
                int nc = j + dc[k];
                
                if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
                if ((board[i][j] & (1 << k)) == 0) continue;
                if (visit[i][j] == visit[nr][nc]) continue;
                
                int totalSize = roomSize[visit[i][j]] + roomSize[visit[nr][nc]];
                widestRoomWhenRemoveWall = max(widestRoomWhenRemoveWall, totalSize);
            }
        }
    }
    
    return {cnt, {widestRoom, widestRoomWhenRemoveWall}};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> M >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> board[i][j];
        }
    }
    
    piii res = solution();
    int numberOfRooms = res.first;
    int widestRoom = res.second.first;
    int widestRoomWhenRemoveWall = res.second.second;
    
    cout << numberOfRooms << "\n";
    cout << widestRoom << "\n";
    cout << widestRoomWhenRemoveWall << "\n";

    return 0;
}
