#include <iostream>

using namespace std;

int N;
string board[20];

// makeMinTail(row): 각 행을 뒤집을지 여부가 row로 주어졌을 때, 뒷면의 최소 개수
int makeMinTail(int row) {
    int ret = 0;
    
    // 각 열을 뒤집을지 말지 여부를 tail 개수가 최소가 되도록 정한다.
    for (int j=0; j<N; j++) {
        int headCnt = 0;
        
        for (int i=0; i<N; i++) {
            bool head = board[i][j] == 'H';
            if ((row & (1 << i)) != 0) head = !head;
            if (head) headCnt++;
        }
        
        ret += min(headCnt, N - headCnt);
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i=0; i<N; i++) cin >> board[i];
    
    int ans = 987654321;
    for (int i=0; i<(1 << N); i++) {
        ans = min(ans, makeMinTail(i));
    }
    
    cout << ans;

    return 0;
}
