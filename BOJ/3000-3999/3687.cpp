#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

int cnt[8] = {0, 0, 1, 7, 4, 2, 6, 8};
ll cache[101];

ll dp(int n) {
    if (n < 8) return cnt[n];
    
    ll& ret = cache[n];
    if (ret != -1) return ret;
    
    ret = dp(n-6)*10;   // 끝이 0
    for (int i=2; i<8; i++) {
        if (n-i < 2) continue;
        ret = min(ret, dp(n-i)*10+cnt[i]);  // 끝이 cnt[i]
    }
    
    return ret;
}

ll makeMinNum(int n) {
    return dp(n);
}

string makeMaxNum(int n) {
    string ret = "";
    
    if (n % 2 == 0) ret += "1";
    else ret += "7";
    
    for (int i=0; i<n/2-1; i++) {
        ret += "1";
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        cout << makeMinNum(n) << " " << makeMaxNum(n) << "\n";
    }

    return 0;
}
