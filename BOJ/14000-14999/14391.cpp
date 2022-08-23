#include <iostream>
#include <vector>

using namespace std;

int N, M;
int board[4][4];

bool isMarked(int r, int c, int mask) {
    int idx = r*M + c;
    return ((1 << idx) & mask) != 0;
}

int calcSum(int mask) {
    int ret = 0;
    vector<vector<bool>> visit(N, vector<bool>(M, 0));
    
    for (int i=0; i<N*M; i++) {
        int r = i/M;
        int c = i%M;
        int nr = r;
        int nc = c;
        int sum = 0;
        
        while (nr < N && nc < M &&
               !visit[nr][nc] &&
               isMarked(r, c, mask) == isMarked(nr, nc, mask)) {
            sum *= 10;
            sum += board[nr][nc];
            visit[nr][nc] = true;
            
            if (isMarked(r, c, mask)) nc++; // 가로 조각
            else nr++;                      // 세로 조각
        }

        ret += sum;
    }
    
    return ret;
}

int optimize() {
    int ret = 0;
    
    for (int i=0; i<(1<<N*M); i++) {
        ret = max(ret, calcSum(i));    
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    for (int i=0; i<N; i++) {
        string temp;
        cin >> temp;
        
        for (int j=0; j<M; j++) {
            board[i][j] = temp[j] - '0';    
        }
    }
    
    cout << optimize();

    return 0;
}
