#include <iostream>
#include <queue>

using namespace std;

int N, M, sr, sc;
string board[51];
bool visit[51][51][1<<6];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

struct Node {
    int r, c, keys;
};

int solution() {
    queue<pair<int, Node>> q;
    visit[sr][sc][0] = true;
    q.push({0, {sr, sc, 0}});
    
    while (!q.empty()) {
        int d = q.front().first;
        Node node = q.front().second;
        q.pop();
        
        for (int i=0; i<4; i++) {
            int nr = node.r + dr[i];
            int nc = node.c + dc[i];
            int x, nkeys;
            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            
            switch (board[nr][nc]) {
                case '.': case '0': 
                    if (!visit[nr][nc][node.keys]) {
                        visit[nr][nc][node.keys] = true;
                        q.push({d+1, {nr, nc, node.keys}});
                    }
                    break;
                case '#': break;
                case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
                    x = board[nr][nc] - 'a';
                    nkeys = node.keys | (1 << x);
                    if (!visit[nr][nc][nkeys]) {
                        visit[nr][nc][nkeys] = true;
                        q.push({d+1, {nr, nc, nkeys}});
                    }
                    break;
                case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
                    x = board[nr][nc] - 'A';
                    if ((node.keys & (1 << x)) != 0 && !visit[nr][nc][node.keys]) {
                        visit[nr][nc][node.keys] = true;
                        q.push({d+1, {nr, nc, node.keys}});
                    }
                    break;
                case '1': return d+1;
            }
        }
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        cin >> board[i];
        for (int j=0; j<M; j++) {
            if (board[i][j] == '0') {
                sr = i;
                sc = j;
            }
        }
    }
    
    cout << solution();    

    return 0;
}
