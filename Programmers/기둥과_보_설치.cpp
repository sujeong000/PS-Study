#include <string>
#include <vector>
#include <iostream>

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
    switch (a) {
        case 0:
            vertical[x][y] = false;
            break;
        case 1:
            horizontal[x][y] = false;
            break;
    }
    
    int dx[] = {-1, 0, 1};
    int dy[] = {-1, 0, 1};
    
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            int ax = x + dx[i];
            int ay = y + dy[j];
            if (!validatePos(ax, ay)) continue;
            
            if (horizontal[ax][ay] && !validateHorizontal(ax, ay)) {
                cancelRemove(x, y, a);
                return;
            }
            if (vertical[ax][ay] && !validateVertical(ax, ay)) {
                cancelRemove(x, y, a);
                return;
            }
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
