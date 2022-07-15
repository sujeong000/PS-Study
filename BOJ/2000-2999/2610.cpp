#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int N, M;
bool adjs[101][101], visit[101];
int dist[101][101], passingTime[101];

void FloydWarshall() {
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (i == j) dist[i][j] = 0;
            else if (adjs[i][j]) dist[i][j] = 1;
            else dist[i][j] = INF;
        }
    }
    
    for (int k=1; k<=N; k++) {
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void calcPassingTime() {
    for (int i=1; i<=N; i++) {
        int maxTime = -1;
        
        for (int j=1; j<=N; j++) {
            if (dist[j][i] == INF) continue;
            maxTime = max(maxTime, dist[j][i]);
        }
        
        passingTime[i] = maxTime;
    }
}

int DFS(int curr) {
    visit[curr] = true;
    
    int leader = curr;
    for (int next=1; next<=N; next++) {
        if (!adjs[curr][next] || visit[next]) continue;
        
        int cand = DFS(next);
        if (passingTime[cand] < passingTime[leader]) leader = cand;
    }
    
    return leader;
}

vector<int> pickLeaders() {
    vector<int> leaders;
    
    for (int i=1; i<=N; i++) {
        if (!visit[i]) leaders.push_back(DFS(i));
    }
    
    return leaders;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        adjs[a][b] = true;
        adjs[b][a] = true;
    }
    
    FloydWarshall();
    calcPassingTime();
    
    vector<int> leaders = pickLeaders();
    sort(leaders.begin(), leaders.end());
    
    cout << leaders.size() << "\n";
    for (auto leader: leaders) cout << leader << "\n";

    return 0;
}
