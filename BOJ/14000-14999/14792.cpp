#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

map<ll, ll> m;

pair<ll, ll> solution(ll N, ll K) {
    ll cnt = 0;
    
    m[N] = 1;
    while (true) {
        ll x = m.rbegin()->first;    // 가장 큰 조각의 크기
        
        // 중앙을 채우고 나면 좌우로 갈라져 새로운 두 조각이 생성된다.
        ll l = (x - 1) / 2;
        ll r = x - l - 1;
        
        ll x_cnt = m[x];
        cnt += x_cnt;
        if (cnt >= K) return {r, l};
        
        // 크기 x짜리 조각을 모두 소진
        m.erase(x);
        
        // 그 결과로 l짜리, r짜리 조각이 x_cnt개 만큼씩 생성됨.
        if (m.find(l) == m.end()) m[l] = 0;
        if (m.find(r) == m.end()) m[r] = 0;
        m[l] += x_cnt;
        m[r] += x_cnt;
    }
    
    return {0, 0};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    
    for (int t=1; t<=T; t++) {
        m.clear();
        
        ll N, K;
        cin >> N >> K;
        
        pair<ll, ll> ans = solution(N, K);
        
        cout << "Case #" << t << ": " << ans.first << " " << ans.second << "\n";
    }

    return 0;
}
