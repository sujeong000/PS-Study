#include <iostream>

using namespace std;

const int INF = 987654321;

int N, K;
int dist[10][10];
int min_cost = INF;

void dfs(int cost, int curr, int visit) {
    if (cost >= min_cost) return;
    if (visit == ((1 << N) -1)) {
        min_cost = min(min_cost, cost);
        return;
    }
    
    for (int next=0; next<N; next++) {
        if ((visit & (1 << next)) != 0) continue;
        dfs(cost + dist[curr][next], next, visit | (1 << next));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> dist[i][j];
        }
    }
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            for (int k=0; k<N; k++) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    
    dfs(0, K, 1<<K);
    
    cout << min_cost;

    return 0;
}
