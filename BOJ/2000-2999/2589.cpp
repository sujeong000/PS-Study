#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int R, C;
char map[50][50];
bool visit[50][50];
queue<pair<int, int>> q;

int BFS(int r, int c) {
    memset(visit, 0, 50*50*sizeof(bool));
    int max_dist = 0;
    
    visit[r][c] = true;
    q.push({r*C+c, 0});
    
    while (!q.empty()) {
        int curr = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        if (dist > max_dist) max_dist = dist;
        
        int row = curr / C;
        int col = curr % C;
        
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        
        for(int i=0; i<4; i++) {
            int nextRow = row + dr[i];
            int nextCol = col + dc[i];
            int next = nextRow * C + nextCol;
            
            if (nextRow < 0 || nextRow >= R || nextCol < 0 || nextCol >= C) continue;
            if (map[nextRow][nextCol] == 'W' || visit[nextRow][nextCol]) continue;
            
            visit[nextRow][nextCol] = true;
            q.push({next, dist + 1});
        }
    }
    
    return max_dist;
}

int findTreasure() {
    int max_dist = 0;
    
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if (map[i][j] == 'W') continue;
            max_dist = max(max_dist, BFS(i, j));        
        }
    }
    
    return max_dist;
}

int main()
{
    cin >> R >> C;
    
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin >> map[i][j];
        }
    }
    
    cout << findTreasure();
    
    return 0;
}
