#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

int INF = 987654321;
int R, C;
int hedgehog_r, hedgehog_c;     // 고슴도치 처음 위치

char map[50][50];
int water_visit[50][50];        // 물이 해당 칸에 며칠날 도착하는지
int hedgehog_visit[50][50];     // 고슴도치가 해당 칸에 며칠날 도착하는지

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int move_hedgehog() {
    queue<pair<int, int>> q;
    
    q.push({hedgehog_r, hedgehog_c});
    hedgehog_visit[hedgehog_r][hedgehog_c] = 1;
    
    while (!q.empty()) {
        int curr_r = q.front().first;
        int curr_c = q.front().second;
        q.pop();
        
        if (map[curr_r][curr_c] == 'D') return hedgehog_visit[curr_r][curr_c] - 1;
        
        for(int i=0; i<4; i++) {
            int next_r = curr_r + dr[i];
            int next_c = curr_c + dc[i];
            
            if (next_r < 0 || next_r >= R || next_c < 0 || next_c >= C) continue;
            if (hedgehog_visit[next_r][next_c]) continue;
            if (map[next_r][next_c] == 'X') continue;
            
            // 해당 칸에 물이 도착하기 전에 도치가 더 빨리 도착할 수 있다면 이동
            if (water_visit[next_r][next_c] > hedgehog_visit[curr_r][curr_c] + 1) {
                q.push({next_r, next_c});
                hedgehog_visit[next_r][next_c] = hedgehog_visit[curr_r][curr_c] + 1;
            }
        }
    }
    
    return 987654321;
}

void flow_water(int r, int c) {
    queue<pair<int, int>> q;
    
    q.push({r, c});
    water_visit[r][c] = 1;
    
    while (!q.empty()) {
        int curr_r = q.front().first;
        int curr_c = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++) {
            int next_r = curr_r + dr[i];
            int next_c = curr_c + dc[i];
            
            if (next_r < 0 || next_r >= R || next_c < 0 || next_c >= C) continue;
            if (map[next_r][next_c] == 'X' || map[next_r][next_c] == 'D') continue;
            if (water_visit[next_r][next_c] <= water_visit[curr_r][curr_c] + 1) continue;
            
            q.push({next_r, next_c});
            water_visit[next_r][next_c] = water_visit[curr_r][curr_c] + 1;
        }
    }
}

int simulate() {
    for(int i=0; i<50; i++) {
        for(int j=0; j<50; j++) {
            water_visit[i][j] = INF;
        }
    }
    
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if (map[i][j] != '*') continue;
            flow_water(i, j);
        }
    }
    
    return move_hedgehog();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C;
    
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin >> map[i][j];
            
            if (map[i][j] == 'S') {
                hedgehog_r = i;
                hedgehog_c = j;
            }
        }   
    }
    
    int result = simulate();
    
    if (result == INF) cout << "KAKTUS";
    else cout << result;

    return 0;
}
