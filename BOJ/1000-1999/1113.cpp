#include <iostream>
#include <string.h>

using namespace std;

int N, M;
int board[52][52];
bool visit[52][52];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void DFS(int r, int c) {
    if (visit[r][c]) return;
    visit[r][c] = true;
    
    for (int i=0; i<4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr < 0 || nr > N+1 || nc < 0 || nc > M+1) continue;
        if (board[nr][nc] != board[r][c]) continue;
        
        DFS(nr, nc);
    }
}

int solution() {
    int ret = 0;
    
    // 하늘에서 비를 내린다고 생각, 낮은 칸부터 차오름
    for (int h=0; h<=9; h++) {
        memset(visit, 0, sizeof(visit));
        
        DFS(0, 0);  // 밖으로 흐르는 칸 체크
        
        for (int i=0; i<=N+1; i++) {
            for (int j=0; j<=M+1; j++) {
                if (board[i][j] == h) {
                    if (!visit[i][j]) ret++;
                    board[i][j]++;
                }
            }
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        string temp; cin >> temp;
    for (int j=1; j<=M; j++) {
            board[i][j] = temp[j-1] - '0';
        }
    }
    
    cout << solution();

    return 0;
}
