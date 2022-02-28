#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <map>
#include <cmath>
#include <vector>
#include <stack>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    
    cin >> T;
    
    while (T--) {
        ll N;
        
        cin >> N;
        
        if (N % 10 == 0) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    
    return 0;
}
