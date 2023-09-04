#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;
typedef long double ld;

ld intersection(ll x, ll r) {
    return sqrt(r*r - x*x);
}

long long solution(int r1, int r2) {
    long long answer = 0;
    
    // x = 0일 때
    answer += 2 * (r2 - r1 + 1);
    
    // x=1부터 x=(r1-1)까지
    for (ll x = 1; x < r1; x++) {
        ll hi = intersection(x, r2);
        ll lo = ceil(intersection(x, r1));
        answer += 4 * (hi - lo + 1);    // x<0, y<0 쪽도 있으므로 4배
    }
    
    // x=r1부터 x=r2까지
    for (ll x = r1; x <= r2; x++) {
        ll hi = intersection(x, r2);
        answer += 2 * (2*hi + 1);   // x<0 쪽도 있으므로 2배
    }
    
    return answer;
}
