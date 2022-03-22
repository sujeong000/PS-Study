#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

ll V, K;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    
    for (int t=1; t<=T; t++) {
        cin >> K >> V;
        
        ll ans = 0;
        
        // i = G-R, j = B-G
        for (ll i = -V; i <= V; i++) {
            for (ll j = -V; j <= V; j++) {
                if (abs(i + j) > V) continue;   // |R-B| > V
                
                // 1. 0 <= R <= K
                // 2. -i <= R <= K-i (because G = R+i, 0 <= R+i <= K)
                // 3. -i-j <= R <= K-i-j (because B = R+i+j, 0 <= R+i+j <= K)
                ll lo = max((ll)0, max(-i, -i-j));
                ll hi = min(K, min(K-i, K-i-j));
                ans += hi - lo + 1;
            }
        }
        
        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}

