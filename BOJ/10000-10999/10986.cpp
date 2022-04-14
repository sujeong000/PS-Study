#include <iostream>

using namespace std;

typedef long long ll;

const int MAX = 1000001;

int N, M;
ll arr[MAX], psum[MAX], cnt[1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        cin >> arr[i];
        psum[i] = (psum[i-1] + arr[i]) % M;
        cnt[psum[i]]++;
    }
    
    ll ans = 0;
    for (int i=0; i<M; i++) ans += cnt[i] * (cnt[i] - 1);
    ans /= 2;
    ans += cnt[0];
    
    cout << ans;

    return 0;
}
