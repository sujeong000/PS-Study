#include <iostream>
#include <cmath>

using namespace std;

int T, N;
char board[201][201];

int solution() {
    int A = 0, B = 0, C = 0, D = 0;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (board[i][j] == 'I') A++;
            if (board[i][N+j] == 'I') B++;
            if (board[N+i][j] == 'I') C++;
            if (board[N+i][N+j] == 'I') D++;
        }
    }
    
    int BC = 987654321;
    int AD = 987654321;
    
    for (int i=0; i<=N*N; i++) {
        BC = min(BC, abs(B-i) + abs(C-i));
        AD = min(AD, abs(A-i) + abs(D-i));
    }
    
    return BC + AD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    
    for (int t=1; t<=T; t++) {
        cin >> N;
        
        string s;
        for (int i=0; i<2*N; i++) {
            cin >> s;
            for (int j=0; j<2*N; j++) board[i][j] = s[j];
        }
    
        int ans = solution();
        
        cout << "Case #" << t << ": ";
        cout << ans;
        cout << "\n";
    }

    return 0;
}
