#include <string>
#include <vector>

using namespace std;
const int REMOVE = 0, ADD = 1;
const int VERTICAL = 0, HORIZONTAL = 1;

int N;
bool vertical[1001][1001];
bool horizontal[1001][1001];

bool validateVertical(int x, int y) {
    if (y == 0) return true;
    if (horizontal[x][y]) return true;
    if (x > 0 && horizontal[x-1][y]) return true;
    if (y > 0 && vertical[x][y-1]) return true;
    return false;
}

bool validateHorizontal(int x, int y) {
    if (y > 0 && vertical[x][y-1]) return true;
    if (x < N && y > 0 && vertical[x+1][y-1]) return true;
    if (x > 0 && horizontal[x-1][y] && x < N && horizontal[x+1][y]) return true;
    return false;
}

bool validateAdjacent(int x, int y) {
    for (int i=x-1; i<=x+1; i++) {
        for (int j=y-1; j<=y+1; j++) {
            if (i < 0 || i > N || j < 0 || j > N) continue;
            if (horizontal[i][j] && !validateHorizontal(i, j)) return false;
            if (vertical[i][j] && !validateVertical(i, j)) return false;
        }
    }
    return true;
}

void addVertical(int x, int y) {
    if (validateVertical(x, y)) {
        vertical[x][y] = true;
    }
}

void addHorizontal(int x, int y) {
    if (validateHorizontal(x, y)) horizontal[x][y] = true;
}

void removeVertical(int x, int y) {
    vertical[x][y] = false;
    if (!validateAdjacent(x, y)) vertical[x][y] = true;
}

void removeHorizontal(int x, int y) {
    horizontal[x][y] = false;
    if (!validateAdjacent(x, y)) horizontal[x][y] = true;
}

void remove(int x, int y, int a) {
    if (a == VERTICAL) removeVertical(x, y);
    else removeHorizontal(x, y);
}

void add(int x, int y, int a) {
    if (a == VERTICAL) addVertical(x, y);
    else addHorizontal(x, y);
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    N = n;
    
    for (auto bf: build_frame) {
        int x = bf[0];
        int y = bf[1];
        int a = bf[2];
        int b = bf[3];
        
        if (b == REMOVE) remove(x, y, a);
        else add(x, y, a);
    }
    
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            if (vertical[i][j]) answer.push_back({i, j, 0});
            if (horizontal[i][j]) answer.push_back({i, j, 1});
        }
    }
    
    return answer;
}
