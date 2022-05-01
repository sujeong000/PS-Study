#include <iostream>

using namespace std;

const int INF = 987654321, TOTAL = 1000000;
int T, c, m, y, k, C, M, Y, K;

void init_testcase() {
    C = INF; M = INF; Y = INF; K = INF;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    for (int t=1; t<=T; t++) {
        init_testcase();
        
        for (int i=0; i<3; i++) {
            cin >> c >> m >> y >> k;
            C = min(C, c); M = min(M, m); Y = min(Y, y); K = min(K, k);
        }
        
        int remain = TOTAL;
        C = min(remain, C); remain -= C;
        M = min(remain, M); remain -= M;
        Y = min(remain, Y); remain -= Y;
        K = min(remain, K); remain -= K;
        
        cout << "Case #" << t << ": ";
        if (remain > 0) cout << "IMPOSSIBLE";
        else cout << C << " " << M << " " << Y << " " << K;
        cout << "\n";
    }

    return 0;
}
