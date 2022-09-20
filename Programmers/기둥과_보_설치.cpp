#include <string>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

int N;
bool horizontal[101][101];
bool vertical[101][101];

bool validateVertical(int x, int y) {
    if (y == 0) return true;
    if (x > 0 && horizontal[x-1][y]) return true;
    if (horizontal[x][y]) return true;
    if (y > 0 && vertical[x][y-1]) return true;
    
    return false;
}

bool validateHorizontal(int x, int y) {
    if (y > 0 && vertical[x][y-1]) return true;
    if (y > 0 && vertical[x+1][y-1]) return true;
    if (x > 0 && x < N-1 && horizontal[x-1][y] && horizontal[x+1][y]) return true;
    
    return false;
}

void add(int x, int y, int a) {
    switch (a) {
        case 0:
            if (validateVertical(x, y)) vertical[x][y] = true;
            break;
        case 1:
            if (validateHorizontal(x, y)) horizontal[x][y] = true;
            break;
    }
}

bool validatePos(int x, int y) {
    return x >= 0 && x <= N && y >= 0 && y <= N;
}

void cancelRemove(int x, int y, int a) {
    switch (a) {
        case 0:
            vertical[x][y] = true;
            break;
        case 1:
            horizontal[x][y] = true;
            break;
    }
}

void remove(int x, int y, int a) {
    vector<pii> adj_h, adj_v;
    
    switch (a) {
        case 0:
            vertical[x][y] = false;
            adj_v.push_back({x, y-1});
            adj_v.push_back({x, y+1});
            adj_h.push_back({x-1, y+1});
            adj_h.push_back({x, y+1});
            adj_h.push_back({x-1, y});
            adj_h.push_back({x, y});
            break;
        case 1:
            horizontal[x][y] = false;
            adj_v.push_back({x, y});
            adj_v.push_back({x, y-1});
            adj_v.push_back({x+1, y});
            adj_v.push_back({x+1, y-1});
            adj_h.push_back({x-1, y});
            adj_h.push_back({x+1, y});
            break;
    }
    
    for (auto adj: adj_h) {
        int ax = adj.first;
        int ay = adj.second;
        
        if (!validatePos(ax, ay) || !horizontal[ax][ay]) continue;
        if (!validateHorizontal(ax, ay)) {
            cancelRemove(x, y, a);
            return;
        }
    }
    
    for (auto adj: adj_v) {
        int ax = adj.first;
        int ay = adj.second;
        
        if (!validatePos(ax, ay) || !vertical[ax][ay]) continue;
        if (!validateVertical(ax, ay)) {
            cancelRemove(x, y, a);
            return;
        }
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    N = n;
    
    for (auto frame: build_frame) {
        int x = frame[0];
        int y = frame[1];
        int a = frame[2];
        int b = frame[3];
        
        switch (b) {
            case 0:
                remove(x, y, a);
                break;
            case 1:
                add(x, y, a);
                break;
        }
    }
    
    for (int i=0; i<=N; i++) {
        for (int j=0; j<=N; j++) {
            if (vertical[i][j]) answer.push_back({i, j, 0});
            if (horizontal[i][j]) answer.push_back({i, j, 1});
        }
    }
    
    return answer;
}
