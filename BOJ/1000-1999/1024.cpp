#include <iostream>

using namespace std;

int N, L;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> L;
    
    int ans = -1, p, q;
    for (int i=L; i<=100; i++) {
        int p = i*(i-1)/2;
        if (p > N) break;
        if ((N-p) % i == 0) {
            ans = i;
            q = (N-p)/i;
            break;
        }
    }
    
    if (ans == -1) cout << ans;
    else {
        for (int i=0; i<ans; i++) {
            cout << q + i << " ";
        }
    }

    return 0;
}
