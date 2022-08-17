#include <iostream>

using namespace std;

typedef long long ll;

ll N, M, a, K;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> a >> K;
    
    ll minRank = (a-K) % M == 0 ? (a-K)/M+1 : (a-K)/M+2;
    ll maxRank = min(N, a-K+1);
    
    cout << maxRank << " " << minRank;

    return 0;
}
