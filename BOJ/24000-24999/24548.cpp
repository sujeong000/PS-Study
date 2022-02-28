#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <map>
#include <cmath>
#include <vector>
#include <stack>

using namespace std;

typedef long long ll;

int N;
string S;
ll cache[100001][3][3][3][3];

ll dp(int idx, int T, int G, int F, int P) {
    if (idx == N) return 0;
    
    ll& ret = cache[idx][T][G][F][P];
    if (ret != -1) return ret;
    
    if (S[idx] == 'T') {
        ret = dp(idx+1, (3+T-1)%3, G, F, P);
        if (G+F+P == 0 && T == 1) ret++;
    }
    else if (S[idx] == 'G') {
        ret = dp(idx+1, T, (3+G-1)%3, F, P);
        if (T+F+P == 0 && G == 1) ret++;
    }
    else if (S[idx] == 'F') {
        ret = dp(idx+1, T, G, (3+F-1)%3, P);
        if (T+G+P == 0 && F == 1) ret++;
    }
    else {
        ret = dp(idx+1, T, G, F, (3+P-1)%3);
        if (T+G+F == 0 && P == 1) ret++;
    }
    
    // cout << "dp(" << idx << ", " << T << ", " << G << ", " << F << ", " << P << ") = " << ret << "\n";
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(cache, -1, sizeof(cache));

    cin >> N >> S;
    
    ll result = 0;
    
    for(int i=0; i<N; i++) {
        result += dp(i, 0, 0, 0, 0);    
    }
    
    cout << result;
    
    return 0;
}
