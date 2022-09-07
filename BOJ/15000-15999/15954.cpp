#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;

int N, K;
ll arr[500];

ld calcV(int s, int len) {
    ll sum = 0;
    ll ssum = 0;
    
    for (int i=0; i<len; i++) {
        sum += arr[s+i];
        ssum += arr[s+i]*arr[s+i];
    }
    
    return (ld)(ssum*len - sum*sum) / (len*len);
}

int main()
{
    cout << fixed;
    cout.precision(20);
    
    cin >> N >> K;
    for (int i=0; i<N; i++) cin >> arr[i];
    
    ld ans = 1e13;
    
    for (int i=0; i<=N-K; i++) {
        for (int j=K; i+j-1<N; j++) {
            ans = min(ans, calcV(i, j));
        }
    }
    
    cout << sqrt(ans);

    return 0;
}
