#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

typedef long double ld;

int N, e, w, s, n;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
ld dp[4];
bool visit[30][30];
ld ans = 0;

void dfs(int x, int y, ld p, int cnt) {
    if (visit[x][y]) return;
    if (cnt == N) {
        ans += p;
        return;
    }
    visit[x][y] = true;
    
    if (cnt < N) {
        for (int i=0; i<4; i++) {
            dfs(x+dx[i], y+dy[i], p*dp[i], cnt+1);
        }    
    }
    
    visit[x][y] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> e >> w >> s >> n;
    dp[0] = (ld)s/100; dp[1] = (ld)n/100; dp[2] = (ld)w/100; dp[3] = (ld)e/100;
    
    dfs(14, 14, 1, 0);
    
    cout << fixed;
    cout.precision(20);
    cout << ans;

    return 0;
}
