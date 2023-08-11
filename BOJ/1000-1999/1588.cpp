#include <iostream>
#include <cmath>

using namespace std;

const int MAX_NUM = 3;
const int MAX_T = 20;
typedef long long ll;
typedef pair<ll, ll> pll;

struct Result {
    ll one, two, three;
    
    Result(ll a=0, ll b=0, ll c=0) {
        one = a;
        two = b;
        three = c;
    }
    
    bool operator !=(const Result& r) const {
        return !(one == r.one && two == r.two && three == r.three);
    }
    
    Result& operator+=(const Result& r) {
        one += r.one;
        two += r.two;
        three += r.three;
        return *this;
    }
};

int X, L, R, N;
Result cache[MAX_NUM + 1][MAX_T + 1];
int base[4][3] = {
    {0, 0, 0},
    {1, 3, 2},
    {2, 1, 1},
    {2, 3, 2}
};

Result toResult(int x) {
    if (x == 1) return {1, 0, 0};
    else if (x == 2) return {0, 1, 0};
    else return {0, 0, 1};
}

// dp(x, depth): x라는 숫자가 t초 후에 갖게 되는 123의 개수
Result dp(int x, int t) {
    if (t == 0) return toResult(x);
    
    Result& ret = cache[x][t];
    if (ret != Result()) return ret;
    
    ret = Result(0, 0, 0);
    for (int i=0; i<3; i++) {
        ret += dp(base[x][i], t-1);
    }
    
    return ret;
}

int log3(ll x) {
    if (x == 0) return 1;
    
    int ret = 0;
    while (x > 1) {
        x /= 3;
        ret++;
    }
    
    return ret;
}

// calc(x, lo, sz): 현재 숫자가 x이고, 커버하는 범위가 [lo, hi]일 때 범위 내 123의 개수
Result calc(int x, ll lo, ll hi) {
    // 커버 범위가 [L, R]에 완전히 포함되는 경우
    if (L <= lo && hi <= R) return dp(x, log3(hi-lo+1));
    // 커버 범위가 [L, R]을 완전히 벗어나는 경우
    if (hi < L || lo > R) return Result(0, 0, 0);
    
    Result ret = {0, 0, 0};
    ll sz = hi - lo + 1;
    
    // 분할정복
    for (int i=0; i<3; i++) {
        ll nlo = lo + sz/3*i;
        ret += calc(base[x][i], nlo, nlo + sz/3 - 1);
    }
    
    return ret;
}

int main() {
    cin >> X >> L >> R >> N;
    Result answer = calc(X, 0, powl(3, N)-1);
    cout << answer.one << " " << answer.two << " " << answer.three;
    
    return 0;
}
