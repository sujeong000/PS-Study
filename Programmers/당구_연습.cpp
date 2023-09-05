#include <string>
#include <vector>

using namespace std;

typedef long long ll;

const ll INF = 987564321;

ll dist(ll startX, ll startY, ll x, ll y) {
    ll dx = startX - x;
    ll dy = startY - y;
    return dx*dx + dy*dy;
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    // 각 벽면을 축으로 대칭이동한다음 시작점과의 거리 구하면 됨
    for (auto ball: balls) {
        int x = ball[0];
        int y = ball[1];
        
        ll minDist = INF;
        
        // 상
        if (!(x == startX && y > startY)) {
            minDist = min(minDist, dist(startX, startY, x, n+n-y));
        }
        // 우
        if (!(y == startY && x > startX)) {
            minDist = min(minDist, dist(startX, startY, m+m-x, y));
        }
        // 하
        if (!(x == startX && y < startY)) {
            minDist = min(minDist, dist(startX, startY, x, -y));
        }
        // 좌
        if (!(y == startY && x < startX)) {
            minDist = min(minDist, dist(startX, startY, -x, y));
        }
    
        answer.push_back(minDist);
    }
    
    return answer;
}
