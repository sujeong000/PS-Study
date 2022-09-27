#include <iostream>

using namespace std;
typedef long long ll;

int N;
ll dist[100001], price[100001], min_price[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i=0; i<N-1; i++) cin >> dist[i];
    for (int i=0; i<N; i++) cin >> price[i];
    
    min_price[0] = price[0];
    for (int i=1; i<N; i++) {
        min_price[i] = min(price[i], min_price[i-1]);
    }
    
    // 가장 싼 곳에서 넣고 온다
    ll ans = 0;
    for (int i=0; i<N-1; i++) ans += dist[i] * min_price[i];
    cout << ans;

    return 0;
}
