#include <iostream>
#include <queue>

using namespace std;

int INF = 987654321;
int N;
int board[50][50];
int dist[2500];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int dijkstra(int start, int end) {
    for (int i=0; i<2500; i++) dist[i] = INF;
    
    pq.push({0, start});
    dist[start] = 0;
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        
        if (dist[curr] < d) continue;
        
        for (int i=0; i<4; i++) {
            int nextRow = curr / N + dr[i];
            int nextCol = curr % N + dc[i];
            int next = nextRow * N + nextCol;
            
            if (nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= N) continue;
            
            int weight;
            if (board[nextRow][nextCol] == 0) weight = 1;
            else weight = 0;
            
            if (dist[curr] + weight < dist[next]) {
                dist[next] = dist[curr] + weight;
                pq.push({dist[next], next});
            }
        }
    }
    
    return dist[end];
}

int main()
{
    scanf("%d", &N);
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%1d", &board[i][j]);    
        }
    }
    
    printf("%d", dijkstra(0, N*N-1));

    return 0;
}
