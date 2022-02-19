#include <iostream>
#include <string.h>

using namespace std;

int N, M, K;
int MAX = 1000000000;
long long cache[101][101][2];

// dp(n, m, t): a가 n개, z가 m개 있을 때 맨 앞이 t인 단어 개수
long long dp(int n, int m, int t) {
    if (n == 0) return t != 0;
    if (m == 0) return t != 1;
    
    long long& ret = cache[n][m][t];
    if (ret != -1) return ret;
    
    if (t == 0) {
        if (n == 0) ret = 0;
        else ret = dp(n-1, m, t) + dp(n-1, m, 1-t);
    }
    else {
        if (m == 0) ret = 0;
        else ret = dp(n, m-1, t) + dp(n, m-1, 1-t);
    }
    
    if (ret > MAX) ret = MAX + 1;
    
    return ret;
}

void find_kth_word(int n, int m, int k) {
    if (dp(n, m, 0) + dp(n, m, 1) < k) {
        cout << -1;
        return;
    }
    
    while (n + m > 0) {
        if (k <= dp(n, m, 0)) {
            cout << "a";
            n--;
        }
        else {
            cout << "z";
            k -= dp(n, m, 0);
            m--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N >> M >> K;
    
    find_kth_word(N, M, K);

    return 0;
}
