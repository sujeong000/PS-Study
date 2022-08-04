#include <iostream>
#include <string.h>

using namespace std;

string S, T;
int cache[4000][4000];

// dp(p, q): S[p...]와 T[q...]가 앞에서부터 몇글자 일치하는지
int dp(int p, int q) {
    if (p >= S.size() || q >= T.size()) return 0;
    
    int& ret = cache[p][q];
    if (ret != -1) return ret;
    
    if (S[p] != T[q]) ret = 0;
    else ret = 1 + dp(p+1, q+1);
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> S >> T;
    
    int maxLen = 0;
    
    for (int i=0; i<S.size(); i++) {
        for (int j=0; j<T.size(); j++) {
            maxLen = max(maxLen, dp(i, j));
        }
    }
    
    cout << maxLen;

    return 0;
}
