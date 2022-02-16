#include <iostream>
#include <vector>

using namespace std;

int e = 0, w = 1, s = 2, n = 3, u = 4, d = 5;
int N, M, X, Y, K;
int dice[6];
int map[20][20];

void simulate(int direction) {
    if (direction == 1) {
        if (Y == M-1) return;
        Y++;
        
        int new_e = dice[u];
        int new_w = dice[d];
        int new_u = dice[w];
        int new_d = dice[e];
        
        dice[e] = new_e; 
        dice[w] = new_w; 
        dice[u] = new_u; 
        dice[d] = new_d;
    }
    else if (direction == 2) {
        if (Y == 0) return;
        Y--;
        
        int new_e = dice[d];
        int new_w = dice[u];
        int new_u = dice[e];
        int new_d = dice[w];
        
        dice[e] = new_e; 
        dice[w] = new_w; 
        dice[u] = new_u; 
        dice[d] = new_d;
    } 
    else if (direction == 3) {
        if (X == 0) return;
        X--;
        
        int new_s = dice[d];
        int new_n = dice[u];
        int new_u = dice[s];
        int new_d = dice[n];
        
        dice[s] = new_s;
        dice[n] = new_n;
        dice[u] = new_u;
        dice[d] = new_d;
    }
    else {
        if (X == N-1) return;
        X++;
        
        int new_s = dice[u];
        int new_n = dice[d];
        int new_u = dice[n];
        int new_d = dice[s];
        
        dice[s] = new_s;
        dice[n] = new_n;
        dice[u] = new_u;
        dice[d] = new_d;
    }
    
    if (map[X][Y] == 0) {
        map[X][Y] = dice[d];
    }
    else {
        dice[d] = map[X][Y];
        map[X][Y] = 0;
    }
    
    cout << dice[u] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> X >> Y >> K;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> map[i][j];
        }
    }
    
    int direction;
    
    for (int i=0; i<K; i++) {
        cin >> direction;
        simulate(direction);
    }

    return 0;
}
