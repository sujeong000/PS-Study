#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int r, c, k;
    bool night;
};

int N, M, K;
int board[1001][1001];
bool visit[1001][1001][11][2];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int solution() {
    queue<pair<int, Node>> q;
    visit[1][1][0];
    q.push({1, {1, 1, 0, 0}});
    
    while (!q.empty()) {
        int dist = q.front().first;
        Node node = q.front().second;
        q.pop();
        
        if (node.r == N && node.c == M) return dist;
        
        for (int i=0; i<4; i++) {
            int nr = node.r + dr[i];
            int nc = node.c + dc[i];
            if (nr < 1 || nr > N || nc < 1 || nc > M) continue;
            
            if (board[nr][nc] == 0) {
                if (!visit[nr][nc][node.k][1-node.night]) {
                    visit[nr][nc][node.k][1-node.night] = true;
                    q.push({dist+1, {nr, nc, node.k, 1-node.night}});
                }
            }
            else {
                if (node.k < K && !node.night && !visit[nr][nc][node.k+1][1-node.night]) {
                    visit[nr][nc][node.k+1][1-node.night] = true;
                    q.push({dist+1, {nr, nc, node.k+1, 1-node.night}});
                }
            }
        }
        
        // 제자리에서 하루를 보내는 경우
        if (!visit[node.r][node.c][node.k][1-node.night]) {
            visit[node.r][node.c][node.k][1-node.night] = true;
            q.push({dist+1, {node.r, node.c, node.k, 1-node.night}});
        }
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> K;
    for (int i=1; i<=N; i++) {
        string s; cin >> s;
        for (int j=1; j<=M; j++) {
            board[i][j] = s[j-1] - '0';
        }
    }
    
    cout << solution();

    return 0;
}
