#include <iostream>
#include <string.h>
#include <string>

using namespace std;

const int IMPOSSIBLE = -987654321;
const int MAX = 1000001;
int N, K;
int cache[MAX][11];

int length(int n) {
    string s = to_string(n);
    return s.size();
}

int ith_num(int n, int i) {
    string s = to_string(n);
    
    return s[i] - '0';
}

int swap_ith_and_jth(int n, int i, int j) {
    string s = to_string(n);
    swap(s[i], s[j]);
    
    return stoi(s);
}

int dp(int n, int k) {
    if (k == 0) return n;
    
    int& ret = cache[n][k];
    if (ret != -1) return ret;
    
    ret = IMPOSSIBLE;
    
    int len = length(n);
    for (int i=0; i<len-1; i++) {
        for (int j=i+1; j<len; j++) {
            if (i == 0 && ith_num(n, j) == 0) continue;
            ret = max(ret, dp(swap_ith_and_jth(n, i, j), k-1));
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N >> K;
    
    int ans = dp(N, K);
    if (ans == IMPOSSIBLE) cout << -1;
    else cout << ans;

    return 0;
}
