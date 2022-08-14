#include <iostream>
#include <vector>

using namespace std;

int N;
bool board[101][101];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

struct Point {
    int x, y;
};

void generateDragonCurve(int x, int y, int d, int g) {
    vector<Point> v;
    
    v.push_back({x, y});
    v.push_back({x+dx[d], y+dy[d]});
    
    while (g--) {
        int sz = v.size();
        int ex = v.back().x;
        int ey = v.back().y;
        
        for (int i=sz-2; i>=0; i--) {
            // 끝점을 기준으로 평행이동
            int tx = v[i].x - ex;
            int ty = v[i].y - ey;
            
            // 시계방향 90도 회전
            swap(tx, ty);
            tx *= -1;
            
            // 다시 평행이동
            tx += ex;
            ty += ey;

            v.push_back({tx, ty});
        }
    }
    
    for (auto point: v) {
        board[point.x][point.y] = true;
    }
}

int countSquare() {
    int cnt = 0;
    
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            if (board[i][j] && board[i+1][j] && board[i][j+1] && board[i+1][j+1]) cnt++;
        }
    }
    
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i=0; i<N; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        generateDragonCurve(x, y, d, g);    
    }
    
    cout << countSquare();

    return 0;
}
