#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int N, M;
int dist[101][101], before[101][101];

void FloydWarshall() {
    for (int k=1; k<=N; k++) {
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=N; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    before[i][j] = k;
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

vector<int> getRoute(int s, int e) {
    if (before[s][e] == s) return {s, e};
    
    vector<int> route;
    auto l = getRoute(s, before[s][e]);
    auto r = getRoute(before[s][e], e);
    
    for (auto node: l) route.push_back(node);
    route.pop_back();
    for (auto node: r) route.push_back(node);
    
    return route;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int i=1; i<=100; i++) {
        for (int j=1; j<=100; j++) {
            dist[i][j] = (i == j) ? 0 : INF;
        }
    }
    
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int a, b, c; cin >> a >> b >> c;
        if (c < dist[a][b]) {
            dist[a][b] = c;
            before[a][b] = a;
        }
    }
    
    FloydWarshall();
    
    for (int s=1; s<=N; s++) {
        for (int e=1; e<=N; e++) {
            if (dist[s][e] == INF) cout << 0 << " ";
            else cout << dist[s][e] << " ";
        }
        cout << "\n";
    }
    
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (dist[i][j] == INF || i == j) {
                cout << 0;
            }
            else {
                vector<int> route = getRoute(i, j);
                cout << route.size() << " ";
                for (auto node: route) cout << node << " ";
            }
            
            cout << "\n";
        }
    }

    return 0;
}
