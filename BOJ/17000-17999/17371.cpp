#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int N;
pii arr[1001];
int dist[1001][1001];
int avg[1001];  // i번째 편의시설로 이사갔을 때 가장 먼곳과 가까운 곳의 평균 * 2

int calcDist(pii a, pii b) {
    int dx = a.first - b.first;
    int dy = a.second - b.second;
    return dx*dx + dy*dy;
}

void calcAllDist() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            dist[i][j] = calcDist(arr[i], arr[j]);
        }
    }
}

void calcAvg() {
    for (int i=0; i<N; i++) {
        avg[i] = *max_element(&dist[i][0], &dist[i][0]+N);
    }
}

pii findOptPlace() {
    calcAllDist();
    calcAvg();
    
    // 가장 먼 곳과의 거리가 가장 짧은 곳을 선택
    int minAvg = *min_element(avg, avg+N);
    
    for (int i=0; i<N; i++) {
        if (avg[i] == minAvg) return arr[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i=0; i<N; i++) {
        int x, y;
        cin >> x >> y;
        arr[i] = {x, y};
    }
    
    pii ans = findOptPlace();
    int x = ans.first;
    int y = ans.second;
    
    cout << x << " " << y << "\n";

    return 0;
}
