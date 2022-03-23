#include <iostream>
#include <string.h>

using namespace std;

int flip_cnt[1001];

void flip(int s, int e) {
    for (int i=s; i<=e; i++) flip_cnt[i]++;
}

int solution(string s, int k) {
    int ret = 0;
    
    for (int i=0; i<s.size()-k+1; i++) {
        if (((s[i] == '-' ? 1 : 0) + flip_cnt[i]) % 2 == 0) continue;
        flip(i, i+k-1);
        ret++;
    }
    
    for (int i=s.size()-k+1; i<s.size(); i++) {
        if (((s[i] == '-' ? 1 : 0) + flip_cnt[i]) % 2 != 0) return -1;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    
    for (int t=1; t<=T; t++) {
        memset(flip_cnt, 0, sizeof(flip_cnt));
        
        string S;
        int K;
        cin >> S >> K;
        
        int ans = solution(S, K);
        
        cout << "Case #" << t << ": ";
        if (ans == -1) cout << "IMPOSSIBLE";
        else cout << ans;
        cout << "\n";
    }

    return 0;
}
