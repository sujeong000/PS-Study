#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int N;
string pw;
ll cache[11];

// 길이가 정확히 len인 비밀번호의 개수
ll nums(int len) {
    if (len == 0) return 1;
    
    ll& ret = cache[len];
    if (ret != -1) return ret;
    
    return ret = nums(len-1) * 26;
}

ll solve() {
    ll ret = 0;
    
    for (int i=0; i<pw.size(); i++) {
        ll c = pw[i] - 'a';
        
        // i번째 문자가 더 앞서면서 길이가 N-i-1 이하인 것 카운트
        if (i != 0) ret++;
        for (int j=0; j<=N-i-1; j++) {
            ret += nums(j) * c;
        }
    }
    
    return ret + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N >> pw;
    cout << solve();
    
    return 0;
}
