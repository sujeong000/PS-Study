#include <iostream>

using namespace std;

int T;
string S;

int solution(string s) {
    int cnt = s[s.size()-1] == '-' ? 1 : 0;
    char curr = s[0];
    
    for (int i=0; i<s.size(); i++) {
        if (s[i] == curr) continue;
        cnt++;
        curr = s[i];
    }
    
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    
    for (int t=1; t<=T; t++) {
        cin >> S;
        
        int ans = solution(S);
        
        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}
