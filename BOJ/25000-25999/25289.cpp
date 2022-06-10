#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int N;
int A[100001], cache[100001][201];
vector<int> appear[101];

int dp(int s, int d) {
    int& ret = cache[s][d+100];
    if (ret != -1) return ret;
    
    int next = A[s] + d;
    if (next < 1 || next > 100) ret = 1;
    else {
        auto ub = upper_bound(appear[next].begin(), appear[next].end(), s);
        if (ub == appear[next].end()) ret = 1;
        else ret = 1 + dp(*ub, d);
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
        cin >> A[i];
        appear[A[i]].push_back(i);
    }
    
    int maxLen = 0;
    for (int i=0; i<N; i++) {
        for (int j=-99; j<=99; j++) {
            maxLen = max(maxLen, dp(i, j));
        }
    }
    cout << maxLen;

    return 0;
}
