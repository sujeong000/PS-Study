#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int M, S, sx, sy;
ll fishes[4][4][8], temp[4][4][8], copied[4][4][8];
int smell[4][4];

int dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void moveFish(int x, int y, int d) {
    for (int i=0; i<8; i++) {
        int nd = (8 + d - i) % 8;
        int nx = x + dx8[nd];
        int ny = y + dy8[nd];
        
        if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
        if (nx == sx && ny == sy) continue;
        if (smell[nx][ny]) continue;
        
        temp[x][y][d] -= fishes[x][y][d];
        temp[nx][ny][nd] += fishes[x][y][d];
        
        return;
    }
}

void moveFishes() {
    copy(&fishes[0][0][0], &fishes[0][0][0]+128, &temp[0][0][0]);
    copy(&fishes[0][0][0], &fishes[0][0][0]+128, &copied[0][0][0]);
    
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            for (int k=0; k<8; k++) {
                moveFish(i, j, k);
            }
        }
    }
    
    copy(&temp[0][0][0], &temp[0][0][0]+128, &fishes[0][0][0]);
}

vector<pii> calcRoute(int a, int b, int c) {
    vector<pii> route;
    int moves[] = {a, b, c};
    int x = sx, y = sy;
    
    for (auto move: moves) {
        x += dx[move];
        y += dy[move];
        if (x < 0 || x >= 4 || y < 0 || y >= 4) return {};
        route.push_back({x, y});
    }
    
    return route;
}

int countRemovedFish(const vector<pii>& route) {
    int cnt = 0;
    set<pii> routeSet;
    
    for (auto pos: route) routeSet.insert(pos);
    
    for (auto pos: routeSet) {
        int x = pos.first;
        int y = pos.second;
        
        for (int i=0; i<8; i++) {
            cnt += fishes[x][y][i];
        }
    }
    
    return cnt;
}

vector<pii> findOptimizedRouteForShark() {
    int maxCnt = -1;
    vector<pii> optRoute;
    
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            for (int k=0; k<4; k++) {
                vector<pii> route  = calcRoute(i, j, k);
                if (route.empty()) continue;
                int cnt = countRemovedFish(route);
                
                if (cnt > maxCnt) {
                    maxCnt = cnt;
                    optRoute = route;
                }
            }
        }
    }
    
    return optRoute;
}

void moveShark(int day) {
    vector<pii> optRoute = findOptimizedRouteForShark();
    
    for (auto pos: optRoute) {
        sx = pos.first;
        sy = pos.second;
        
        for (int i=0; i<8; i++) {
            if (fishes[sx][sy][i] > 0) smell[sx][sy] = day;
            fishes[sx][sy][i] = 0;
        }
    }
}

void removeSmell(int day) {
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (smell[i][j] == day-2) {
                smell[i][j] = 0;
            }
        }
    }
}

void copyFishes() {
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            for (int k=0; k<8; k++) {
                fishes[i][j][k] += copied[i][j][k];
            }
        }
    }
}

void simulate(int day) {
    moveFishes();
    moveShark(day);
    removeSmell(day);
    copyFishes();
}

ll countFishes() {
    ll cnt = 0;
    
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            for (int k=0; k<8; k++) {
                cnt += fishes[i][j][k];
            }
        }
    }
    
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> M >> S;
    
    for (int i=0; i<M; i++) {
        int x, y, d; 
        cin >> x >> y >> d;
        x--; y--; d--;
        fishes[x][y][d]++;
    }
    
    cin >> sx >> sy;
    sx--; sy--;
    
    for (int day=1; day<=S; day++) {
        simulate(day);
    }
    
    cout << countFishes();
    
    return 0;
}
