#include <iostream>
#include <string.h>

using namespace std;
typedef long long ll;

ll cache[21][21][21];

ll dp(int n, int l, int r) {
    if (n == 1) {
        if (l == 1 && r == 1) return 1;
        else return 0;
    }
    
    ll& ret = cache[n][l][r];
    if (ret != -1) return ret;
    
    ret = dp(n-1, l-1, r) + dp(n-1, l, r-1) + dp(n-1, l, r)*(n-2);
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    int T; cin >> T;
    while (T--) {
        int n, l, r;
        cin >> n >> l >> r;
        cout << dp(n, l, r) << "\n";
    }

    return 0;
}
