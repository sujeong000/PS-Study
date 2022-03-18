// 서브태스크 12점, Test set 2는 백트래킹으로 불가능
#include <iostream>

using namespace std;

const int INF = 987654321;
const int MAX = 51;
int M, N, P, A, B;
bool adj[MAX][MAX];

int min_time = INF;

void backtrack(int d) {
    if (d > 11) return;
    
    if (adj[A][B]) {
        min_time = min(min_time, d);
        return;
    }
    
    for (int i=1; i<=M; i++) {
        for (int j=1; j<M+N; j++) {
            if (!adj[i][j]) continue;
            
            for (int k=i+1; k<=M+N; k++) {
                if (!adj[i][k] || adj[j][k]) continue;
                
                adj[j][k] = true; adj[k][j] = true;
                backtrack(d+1);
                adj[j][k] = false; adj[k][j] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    
    for (int t=1; t<=T; t++) {
        cin >> M >> N >> P;
        
        string s;
        
        for (int i=1; i<=M+N; i++) {
            cin >> s;
            
            for (int j=1; j<=M+N; j++)
                adj[i][j] = s[j-1] == 'Y';
        }
        
        cout << "Case #" << t << ": "; 
        for (int i=0; i<P; i++) {
            cin >> A >> B;
            
            min_time = INF;
            backtrack(0);
            
            if (min_time == INF) cout << -1;
            else cout << min_time;
            cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
