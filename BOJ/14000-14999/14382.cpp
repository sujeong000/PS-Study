#include <iostream>

using namespace std;

typedef long long ll;

ll T, N;

ll solution(int n) {
    // 0을 제외하고는 불가능한 경우 없음. 브루트포스로 확인 가능
    if (n == 0) return -1;
    
    int mask = 0;
    ll i = 1;
    
    while (true) {
        ll curr = n * i;
        
        while (curr > 0) {
            mask |= (1 << (curr % 10));
            curr /= 10;
        }
        
        if (mask == ((1 << 10) - 1)) return n * i;
        i++;
    }
    
    return -1;
}

int main() {
    cin >> T;
    
    for (int t=1; t<=T; t++) {
        cin >> N;
        
        ll ans = solution(N);
        
        cout << "Case #" << t << ": ";
        if (ans == -1) cout << "INSOMNIA";
        else cout << ans;
        cout << "\n";
    }
}
