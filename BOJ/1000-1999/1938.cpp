#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int H = 0, V = 1;
const int UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3, TURN = 4;

int N;
char board[50][50];
bool visit[50][50][2];

struct Log {
    int r, c, d;
    
    bool operator ==(Log& l) {
        return r == l.r && c == l.c && d == l.d;
    }
    
    vector<Log> wholeLogs() {
        vector<Log> ret;
        
        int dr[2][3] = {{0, 0, 0}, {-1, 0, 1}};
        int dc[2][3] = {{-1, 0, 1}, {0, 0, 0}};
        
        for (int i=0; i<3; i++) {
            ret.push_back({r+dr[d][i], c+dc[d][i]});
        }
        
        return ret;
    }
    
    Log moved(int direction) {
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        if (direction == TURN) return {r, c, 1-d};
        else return {r+dr[direction], c+dc[direction], d};
    }
    
    bool canMove(int direction) {
        if (direction != TURN) {
            Log movedLog = moved(direction);
            vector<Log> movedLogs = movedLog.wholeLogs();
            
            for (auto l: movedLogs) {
                if (l.r < 0 || l.r >= N || l.c < 0 || l.c >= N) return false;
                if (board[l.r][l.c] == '1') return false;
            }
        }
        else {
            for (int i=-1; i<=1; i++) {
                for (int j=-1; j<=1; j++) {
                    int nr = r+i;
                    int nc = c+j;
                    if (nr < 0 || nr >= N || nc < 0 || nc >= N) return false;
                    if (board[nr][nc] == '1') return false;
                }
            }
        }
        
        return true;
    }
};

int BFS(Log s, Log e) {
    queue<pair<int, Log>> q;
    
    q.push({0, s});
    visit[s.r][s.c][s.d] = true;
    
    while (!q.empty()) {
        int dist = q.front().first;
        Log curr = q.front().second;
        q.pop();
        
        if (curr == e) return dist;
        
        for (int i=0; i<5; i++) {
            Log next = curr.moved(i);
            
            if (visit[next.r][next.c][next.d]) continue;
            if (!curr.canMove(i)) continue;
            
            visit[next.r][next.c][next.d] = true;
            q.push({dist+1, next});
        }
    }
    
    return 0;
}

Log findMiddleLog(vector<pair<int, int>> v) {
    sort(v.begin(), v.end());
    
    int r = v[1].first;
    int c = v[1].second;
    int d = v[0].first == v[1].first ? H : V;
    
    return {r, c, d};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<pair<int, int>> s, e;
    
    cin >> N;
    for (int i=0; i<N; i++) {
        string temp;
        cin >> temp;
        
        for (int j=0; j<N; j++) {
            board[i][j] = temp[j];
            
            if (board[i][j] == 'B') s.push_back({i, j});
            else if (board[i][j] == 'E') e.push_back({i, j});
        }
    }
    
    cout << BFS(findMiddleLog(s), findMiddleLog(e));

    return 0;
}
