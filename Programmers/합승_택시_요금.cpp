#include <string>
#include <vector>

using namespace std;
const int INF = 987654321;

vector<vector<int>> floydWarshall(int n, const vector<vector<int>>& adjs) {
    vector<vector<int>> dist = adjs;
    
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    return dist;
}

vector<vector<int>> calcAdjacent(int n, const vector<vector<int>> fares) {
    vector<vector<int>> adjs(n+1, vector<int>(n+1, INF));
    
    for (int i=1; i<=n; i++) adjs[i][i] = 0;
    
    for (auto fare: fares) {
        int c = fare[0];
        int d = fare[1];
        int f = fare[2];
        adjs[c][d] = f;
        adjs[d][c] = f;
    }
    
    return adjs;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    
    auto adjs = calcAdjacent(n, fares);
    auto dist = floydWarshall(n, adjs);
    
    for (int i=1; i<=n; i++) {
        int common_dist = dist[s][i];
        int muji_dist = dist[i][a];
        int apeach_dist = dist[i][b];
        if (common_dist == INF || muji_dist == INF || apeach_dist == INF) continue;
        
        int total_dist = common_dist + muji_dist + apeach_dist;
        answer = min(answer, total_dist);
    }
    
    return answer;
}
