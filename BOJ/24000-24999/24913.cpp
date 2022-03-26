#include <iostream>
#include <string.h>

using namespace std;

typedef long long ll;

const int MAX = 100002;
ll N, Q;
ll arr[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> Q;
    
    ll max_val = 0, sum = 0;
    
    ll t, x, y;
    for (int i=0; i<Q; i++) {
        cin >> t >> x >> y;
        
        if (t == 1) {
            arr[y] += x;
            
            if (y != N+1) {
                sum += x;
                max_val = max(max_val, arr[y]);
            }
        }
        else {
            ll hoo = arr[N+1] + x;
            if (max_val < hoo && sum+y <= N*(hoo-1)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
