#include <iostream>
#include <vector>

using namespace std;

int N, M, H;
int minCnt = 4;
bool edge[31][11];

bool check() {
    for (int i=1; i<=N; i++) {
        int pos = i;
        
        for (int j=1; j<=H; j++) {
            if (edge[j][pos]) pos++;
            else if (edge[j][pos-1]) pos--;
        }
        
        if (pos != i) return false;
    }
    
    return true;
}

void DFS(int h, int cnt) {
    if (cnt >= minCnt) return;
    if (check()) minCnt = cnt;
    
    for (int i=h; i<=H; i++) {
        for (int j=1; j<N; j++) {
            if (edge[i][j] || edge[i][j-1] || edge[i][j+1]) continue;
            
            edge[i][j] = true;
            DFS(i, cnt+1);
            edge[i][j] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> H;
    
    for (int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        edge[a][b] = true;
    }
    
    DFS(1, 0);
    
    if (minCnt > 3) cout << -1;
    else cout << minCnt;

    return 0;
}
