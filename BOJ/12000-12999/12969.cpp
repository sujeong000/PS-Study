#include <iostream>
#include <string.h>

using namespace std;

int N, K;
int cache[31][31][31][900];

// dp(a, b, c, k) = 'A', 'B', 'C'를 각각 a, b, c개 가지고 오름차순 쌍이 k개가 되도록 만든 문자열
int dp(int a, int b, int c, int k) {
    if (k < 0) return 0;
    if (a + b + c == 1) return k == 0;
    
    int& ret = cache[a][b][c][k];
    if (ret != -1) return ret;
    
    int sa = a > 0 ? dp(a-1, b, c, k-b-c) : 0;
    int sb = b > 0 ? dp(a, b-1, c, k-c) : 0;
    int sc = c > 0 ? dp(a, b, c-1, k) : 0;
    
    ret = sa + sb + sc;
    if (ret > 1) ret = 1;
    
    return ret;
}

string backtrack(int a, int b, int c, int k) {
    if (a + b + c == 1) {
        if (a == 1) return "A";
        if (b == 1) return "B";
        if (c == 1) return "C";
    }
    
    if (a > 0 && dp(a-1, b, c, k-b-c)) return "A" + backtrack(a-1, b, c, k-b-c);
    if (b > 0 && dp(a, b-1, c, k-c)) return "B" + backtrack(a, b-1, c, k-c);
    if (c > 0 && dp(a, b, c-1, k)) return "C" + backtrack(a, b, c-1, k);
    
    return "-1";
}

string solution() {
    memset(cache, -1, sizeof(cache));
    
    for (int a=0; a<=N; a++) {
        for (int b=0; b<=N-a; b++) {
            int c = N - a - b;
            if (dp(a, b, c, K) != 0) return backtrack(a, b, c, K);
        }
    }
    
    return "-1";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    cout << solution();
    
    return 0;
}
