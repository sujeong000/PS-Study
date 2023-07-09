#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

const int MAX_N = 600;
const char EMPTY = 'O', WALL = 'X', DOYEON = 'I', PERSON = 'P';

int N, M;
int sr, sc;
string board[MAX_N];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int BFS() {
    int count_person = 0;
    queue<pii> q;
    vector<vector<bool>> visit(N, vector<bool>(M, 0));
    
    q.push({sr, sc});
    visit[sr][sc] = true;
    
    while (!q.empty()) {
        pii curr = q.front(); q.pop();
        int r = curr.first;
        int c = curr.second;
        
        // 사람을 만날 때마다 카운트
        if (board[r][c] == PERSON) count_person++;
        
        for (int i=0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if (visit[nr][nc] || board[nr][nc] == WALL) continue;

            q.push({nr, nc});
            visit[nr][nc] = true;
        }
    }
    
    return count_person;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        cin >> board[i];
        
        for (int j=0; j<M; j++) {
            // 도연이의 위치 저장
            if (board[i][j] == DOYEON) {
                sr = i;
                sc = j;
            }
        }
    }
    
    int answer = BFS();
    
    if (answer) cout << answer;
    else cout << "TT";
}
