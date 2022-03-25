#include <iostream>
#include <algorithm>

using namespace std;

int T, Smax;
string S;

int solution(string s) {
    int sum = 0;
    int add = 0;
    
    for (int i=0; i<s.size(); i++) {
        if (sum < i) {
            int invite = i - sum;
            add += invite;
            sum += invite;
        }
        
        sum += s[i] - '0';
    }
    
    return add;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    
    for (int t=1; t<=T; t++) {
        cin >> Smax >> S;
        
        int ans = solution(S);
        
        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}
