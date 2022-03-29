#include <iostream>

using namespace std;

int T;
long double D, N, K, S;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cout << fixed;
    cout.precision(10);
    
    cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> D >> N;
        
        long double max_time_cost = 0;
        for (int i=0; i<N; i++) {
            cin >> K >> S;
            
            long double time_cost = (D-K)/S;
            max_time_cost = max(max_time_cost, time_cost);
        }
        
        long double ans = D / max_time_cost;
        
        cout << "Case #" << t << ": ";
        cout << ans;
        cout << "\n";
    }
    
    return 0;
}
