#include <iostream>

using namespace std;

long long D, K, N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    
    for (int t=1; t<=T; t++) {
        cin >> D >> K >> N;
        
        long long l, r;
        
        if (K % 2 != 0) l = (K+1 + (N%D)*2) % D;
        else l = (K+1 - (N%D)*2 + 2*D) % D;
        
        r = (l - 2 + D) % D;
        
        if (l == 0) l = D;
        if (r == 0) r = D;
        
        cout << "Case #" << t << ": " << l << " " << r << "\n";
    }

    return 0;
}
