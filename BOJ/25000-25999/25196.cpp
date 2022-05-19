#include <iostream>

using namespace std;

typedef long long ll;

ll Av, As, Ae, Bv, Bs, Be, Cv, Cs, Ce;
ll INF;

ll solution(ll av, ll as, ll ae, ll bv, ll bs, ll be, ll cv, ll cs, ll ce) {
    ll ret = as;
    
    // 새 3마리가 최초로 모두 보이는 시점은 항상 어떤 새의 시작점이다.
    // A새의 모든 시작점에 대해 B, C와 만나는 점이 있는지 확인
    while (ret < INF) {
        while (be < ret) {
            bs += bv;
            be += bv;   
        }
        while (ce < ret) {
            cs += cv;
            ce += cv;
        }
        
        if (bs <= ret && ret <= be && cs <= ret && ret <= ce) return ret;
        ret += av;
    }
    
    return INF;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> Av >> As >> Ae;
    cin >> Bv >> Bs >> Be;
    cin >> Cv >> Cs >> Ce;
    
    INF = Av*Bv*Cv;
    
    ll ra = solution(Av, As, Ae, Bv, Bs, Be, Cv, Cs, Ce);
    ll rb = solution(Bv, Bs, Be, Av, As, Ae, Cv, Cs, Ce);
    ll rc = solution(Cv, Cs, Ce, Av, As, Ae, Bv, Bs, Be);
    ll ans = min(min(ra, rb), rc);
    
    if (ans == INF) cout << -1;
    else cout << ans;

    return 0;
}
