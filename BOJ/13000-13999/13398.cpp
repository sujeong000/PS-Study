#include <iostream>
#include <string.h>

using namespace std;

typedef long long ll;

const int MAX = 100002, MIN = -987654321;
int N;
ll arr[MAX], dp[MAX][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i];
    
    for (int i=N-1; i>=0; i--) {
        for (int j=0; j<2; j++) {
            dp[i][j] = max(arr[i], arr[i]+dp[i+1][j]);
            if (j == 0) dp[i][j] = max(dp[i][j], arr[i]+dp[i+2][1]);
        }
    }
    
    ll ans = MIN;
    for (int i=0; i<N; i++) ans = max(ans, dp[i][0]);
    
    cout << ans;

    return 0;
}
