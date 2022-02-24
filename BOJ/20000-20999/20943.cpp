#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<long long, long long> pll;

int N;
pll lines[500001];

bool cmp(pll lhs, pll rhs) {
    if (lhs.second == 0) return false;
    if (rhs.second == 0) return true;
    
    bool lhs_is_positive = -(lhs.first * lhs.second) > 0;
    bool rhs_is_positive = -(rhs.first * rhs.second) > 0;
    
    if (lhs.first == 0) return rhs_is_positive;
    if (rhs.first == 0) return !lhs_is_positive;
    
    if (lhs_is_positive && !rhs_is_positive) return false;
    if (rhs_is_positive && !lhs_is_positive) return true;
    
    if (lhs_is_positive) return abs(lhs.first * rhs.second) < abs(rhs.first * lhs.second);
    else return abs(lhs.first * rhs.second) > abs(rhs.first * lhs.second);
}

bool parallel(pll lhs, pll rhs) {
    if (lhs.second == 0) return rhs.second == 0;
    if (rhs.second == 0) return lhs.second == 0;
    if (lhs.first == 0) return rhs.first == 0;
    if (rhs.first == 0) return lhs.first == 0;
    
    bool lhs_is_positive = -(lhs.first * lhs.second) > 0;
    bool rhs_is_positive = -(rhs.first * rhs.second) > 0;
    
    if (lhs_is_positive && !rhs_is_positive) return false;
    if (rhs_is_positive && !lhs_is_positive) return false;
    
    return abs(lhs.first * rhs.second) == abs(rhs.first * lhs.second);
}

long long count_pairs() {
    sort(lines, lines+N, cmp);
    
    long long ret = 0;
    int idx = 0;
    int before_idx = 0;
    
    while (idx < N) {
        while (idx < N && parallel(lines[before_idx], lines[idx])) idx++;
        
        long long cnt = idx - before_idx;
        ret += cnt * (N - cnt);
        
        before_idx = idx;
    }
    
    return ret / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    long long a, b, c;
    
    for(int i=0; i<N; i++) {
        cin >> a >> b >> c;
        lines[i] = {a, b};
    }
    
    cout << count_pairs();

    return 0;
}
