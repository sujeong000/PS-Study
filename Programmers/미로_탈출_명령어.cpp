#include <string>
#include <vector>
#include <string.h>
#include <iostream>

using namespace std;
const int MAX_N = 51;
const int MAX_K = 2'501;

int N, M, SR, SC, ER, EC, K;
int cache[MAX_N][MAX_N][MAX_K];
char dir[] = {'d', 'l', 'r', 'u'};
int dr[] = {1, 0, 0, -1};
int dc[] = {0, -1, 1, 0};
char answer[MAX_K];

// dp(r, c, k): (r,c)에서 정확히 k번의 이동으로 도착지점에 갈 수 있는가
int dp(int r, int c, int k) {
    if (k == 0) {
        // 도착 지점 도달했는지 여부
        return (r == ER && c == EC);
    }
    
    int& ret = cache[r][c][k];
    if (ret != -1) return ret;
    
    ret = 0;
    if (k > 0) {
        for (int i=0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (nr < 1 || nr > N || nc < 1 || nc > M) continue;
            
            // 다음 칸으로 이동
            ret = max(ret, dp(nr, nc, k-1));
        }
    }
    
    return ret;
}

void track(int r, int c, int k, string& route) {
    if (k == 0) return;
    
    // d-l-r-u 순으로 탐색
    for (int i=0; i<4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if (nr < 1 || nr > N || nc < 1 || nc > M) continue;
        
        if (dp(nr, nc, k-1)) {          // (nr, nc)로 가서 탈출이 가능하다면
            route[K-k] = dir[i];        // (nr, nc)로 이동
            track(nr, nc, k-1, route);  // 이어서 다음 경로 찾기
            return;   
        }
    }
}

string calcRoute() {
    string route(K, ' ');
    
    track(SR, SC, K, route);
    
    return route;
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    N = n; M = m; SR = x; SC = y; ER = r; EC = c; K = k;
    
    memset(cache, -1, sizeof(cache));
    answer = dp(SR, SC, K) ? calcRoute() : "impossible";
    
    return answer;
}
