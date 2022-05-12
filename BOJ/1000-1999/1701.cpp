#include <iostream>
#include <string.h>

using namespace std;

const int MAX = 5000;

string S;
int cache[MAX][MAX];

// dp(a, b): 가장 길게 일치하는 부분문자열 S[a...]와 S[b...]의 길이
int dp(int a, int b) {
    if (b == S.size() || a == b) return 0;
    
    int& ret = cache[a][b];
    if (ret != -1) return ret;
    
    if (S[a] != S[b]) ret = 0;
    else ret = 1 + dp(a+1, b+1);
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> S;
    
    int max_len = 0;
    for (int i=0; i<S.size()-1; i++) {
        for (int j=i+1; j<S.size(); j++) {
            max_len = max(max_len, dp(i, j));
        }
    }
    
    cout << max_len;

    return 0;
}
