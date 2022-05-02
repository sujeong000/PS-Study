#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

int N;
int arr[8], pick[8];

int brute_force(int idx, int mask) {
    if (idx == N) {
        int ret = 0;
        for (int i=0; i<N-1; i++) {
            ret += abs(arr[pick[i+1]] - arr[pick[i]]);
        }
        return ret;
    }
    
    int ret = 0;
    
    for (int i=0; i<N; i++) {
        if ((mask & (1 << i)) != 0) continue;
        pick[idx] = i;
        ret = max(ret, brute_force(idx+1, mask|(1<<i)));
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i];
    
    cout << brute_force(0, 0);

    return 0;
}
