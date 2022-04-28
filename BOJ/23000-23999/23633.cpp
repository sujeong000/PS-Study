#include <iostream>
#include <string.h>

using namespace std;

int T, A, B;
int cache[2001], prime_cnt[2001];
bool is_prime[2001];

// dp(curr): 현재까지 합쳐서 curr번의 벨이 울렸을 때, 현재 턴의 사람이 얻을 수 있는 최대 점수
int dp(int curr) {
    if (curr == B) return 0;
    
    int& ret = cache[curr];
    if (ret != -1) return ret;
    
    ret = 0;
    for (int i=1; i<=A; i++) {
        if (curr+i > B) break;
        int score = prime_cnt[B] - prime_cnt[curr] - dp(curr+i);
        ret = max(ret, score);
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i=2; i<2001; i++) is_prime[i] = true;
    for (int i=2; i<2001; i++) {
        if (!is_prime[i]) continue;
        
        int x = i*2;
        while (x < 2001) {
            is_prime[x] = false;
            x += i;
        }
    }
    for (int i=1; i<2001; i++) {
        prime_cnt[i] = prime_cnt[i-1];
        if (is_prime[i]) prime_cnt[i]++;
    }
    
    cin >> T;
    while (T--) {
        memset(cache, -1, sizeof(cache));
        
        cin >> A >> B;
        
        int kuro = dp(0);
        int siro = prime_cnt[B] - kuro;
        
        if (kuro > siro) cout << "kuro";
        else if (kuro < siro) cout << "siro";
        else cout << "draw";
        cout << "\n";
    }

    return 0;
}
