#include <iostream>
#include <string.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int MAX = 26;
int R, C;
ll cache[MAX][MAX];

ll dp(int r, int c) {
    if (r == 1 || c == 1) return 1;
    
    ll& ret = cache[r][c];
    if (ret != -1) return ret;
    
    // i행에서 오른쪽으로 꺾으면 더이상 i행 위로는 방문할 수 없다.
    // r-i행에서 오른쪽으로 꺾으면 dp(i, c-1)인 상황과 같아진다.
    // 0행~(r-1)행에서 꺾는 모든 경우를 더한다.
    ret = 0;
    for (int i=1; i<=r; i++) ret += dp(i, c-1);
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    int T;
    cin >> T;
    
    for (int t=1; t<=T; t++) {
        cin >> R >> C;
        
        ll ans = dp(R, C);
        
        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}
