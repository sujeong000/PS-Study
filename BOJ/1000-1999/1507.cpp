#include <iostream>

using namespace std;

int N;
int adjs[20][20], dist[20][20];
bool used[20][20];

void FloydWarshall() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            used[i][j] = true;
            dist[i][j] = adjs[i][j];
        }
    }
    
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++) {
            for (int k=0; k<N; k++) {
                if (i == k || j == k) continue;
                
                if (dist[i][k] + dist[k][j] <= dist[i][j]) {
                    used[i][j] = false;
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

bool check() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (dist[i][j] != adjs[i][j]) return false;
        }
    }
    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> adjs[i][j];
        }
    }
    
    FloydWarshall();
    
    if (!check()) cout << -1;
    else {
        int ans = 0;
    
        for (int i=0; i<N-1; i++) {
            for (int j=i+1; j<N; j++) {
                if (used[i][j]) ans += adjs[i][j];
            }
        }
        
        cout << ans;
    }

    return 0;
}
