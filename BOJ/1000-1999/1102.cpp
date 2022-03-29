#include <iostream>
#include <string.h>

using namespace std;

const int INF = 987654321;
int N, P, on, min_cost = INF;
int adj[16][16], cache[1 << 16];

int count_on(int state) {
    int ret = 0;
    
    for (int i=0; i<16; i++) {
        if ((state & (1 << i)) != 0) ret++;
    }
    
    return ret;
}

int dp(int state) {
    if (count_on(state) >= P) return 0;
    
    int& ret = cache[state];
    if (ret != -1) return ret;
    
    // 켜져 있는 발전소 with를 이용해서 next를 켠다.
    ret = INF;
    for (int next=0; next<N; next++) {
        if ((state & (1 << next)) != 0) continue;
        
        for (int with=0; with<N; with++) {
            if ((state & (1 << with)) == 0) continue;
            ret = min(ret, adj[with][next] + dp(state | (1 << next)));
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> adj[i][j];
        }
    }
    
    string state;
    cin >> state;
    for (int i=0; i<N; i++) {
        if (state[i] == 'Y') on |= (1 << i);
    }
    
    cin >> P;
    
    int ans = dp(on);
    if (ans == INF) cout << -1;
    else cout << ans;
    
    return 0;
}
