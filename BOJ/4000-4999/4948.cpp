#include <iostream>

using namespace std;

const int MAX = 300001;

int N;
int prime_cnt[MAX];
bool is_prime[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int i=2; i<MAX; i++) is_prime[i] = true;
    for (int i=2; i<MAX; i++) {
        if (!is_prime[i]) continue;
        
        int x = i*2;
        while (x < MAX) {
            is_prime[x] = false;
            x += i;
        }
    }
    for (int i=2; i<MAX; i++) {
        prime_cnt[i] = prime_cnt[i-1];
        if (is_prime[i]) prime_cnt[i]++;
    }
    
    while (true) {
        cin >> N;
        if (N == 0) break;
        
        cout << prime_cnt[2*N] - prime_cnt[N] << "\n";
    }

    return 0;
}
