#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, pii> piiii;
const int EMPTY = 0, WALL = 1;
const int INF = 987654321;

int N, M, fuel, R, C;
int board[20][20], dist[20][20][20][20];
piiii passengers[400];
bool finished[400];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void dijkstra() {
    fill(&dist[0][0][0][0], &dist[0][0][0][0]+20*20*20*20, INF);
    
    for (int r=0; r<N; r++) {
        for (int c=0; c<N; c++) {
            dist[r][c][r][c] = 0;
            if (board[r][c] == WALL) continue;
            
            for (int i=0; i<4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
                if (board[nr][nc] == WALL) continue;
                
                dist[r][c][nr][nc] = 1;
            }
        }
    }
    
    for (int k=0; k<N*N; k++) {
        for (int i=0; i<N*N; i++) {
            for (int j=0; j<N*N; j++) {
                int& curr_dist = dist[i/N][i%N][j/N][j%N];
                int new_dist = dist[i/N][i%N][k/N][k%N] + dist[k/N][k%N][j/N][j%N];
                curr_dist = min(curr_dist, new_dist);
            }
        }
    }
}

pii findNearestPassenger(int r, int c) {
    int min_idx = -1;
    int min_dist = INF;
    
    for (int i=0; i<M; i++) {
        if (finished[i]) continue;
        
        pii start_pos = passengers[i].first;
        int pr = start_pos.first;
        int pc = start_pos.second;
        
        if (dist[r][c][pr][pc] < min_dist) {
            min_dist = dist[r][c][pr][pc];
            min_idx = i;
        }
    }
    
    return {min_idx, min_dist};
}

int calcDistToDestination(piiii passenger) {
    int sr = passenger.first.first;
    int sc = passenger.first.second;
    int er = passenger.second.first;
    int ec = passenger.second.second;
    
    return dist[sr][sc][er][ec];
}

int simulate(int r, int c, int fuel) {
    dijkstra();
    
    for (int i=0; i<M; i++) {
        pii next_passenger = findNearestPassenger(r, c);
        int idx = next_passenger.first;
        int dist_to_passenger = next_passenger.second;
        
        if (idx == -1) return -1;
        
        int dist_to_destination = calcDistToDestination(passengers[idx]);
        int total_dist = dist_to_passenger + dist_to_destination;
        
        if (fuel < total_dist) return -1;
        
        finished[idx] = true;
        fuel -= total_dist;
        fuel += dist_to_destination*2;
        r = passengers[idx].second.first;
        c = passengers[idx].second.second;
    }
    
    return fuel;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> fuel;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> board[i][j];
        }
    }
    
    cin >> R >> C;
    R--; C--;
    
    for (int i=0; i<M; i++) {
        int sr, sc, er, ec;
        cin >> sr >> sc >> er >> ec;
        sr--; sc--; er--; ec--;
        
        passengers[i] = {{sr, sc}, {er, ec}};
    }
    
    sort(passengers, passengers+M);
    
    cout << simulate(R, C, fuel);

    return 0;
}
