#include <iostream>

using namespace std;

int T, N;
bool is_prime[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    
    for (int i=2; i<10001; i++) is_prime[i] = true;
    for (int i=2; i<10001; i++) {
        if (!is_prime[i]) continue;
        
        int x = i*2;
        while (x < 10001) {
            is_prime[x] = false;
            x += i;
        }
    }
    
    cin >> T;
    while (T--) {
        cin >> N;
        
        int a;
        for (int i=2; i<=N/2; i++) {
            if (is_prime[i] && is_prime[N-i]) a = i;
        }
        
        cout << a << " " << N-a << "\n";
    }

    return 0;
}
