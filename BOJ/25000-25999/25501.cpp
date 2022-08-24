#include <iostream>

using namespace std;

int callCnt;

int recursion(const string& s, int l, int r) {
    callCnt++;
    if (l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

pair<int, int> isPalindrome(const string& s){
    callCnt = 0;
    int res = recursion(s, 0, s.size()-1);
    
    return {res, callCnt};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    
    while (T--) {
        string s; cin >> s;
        
        auto ans = isPalindrome(s);
        cout << ans.first << " " << ans.second << "\n";
    }

    return 0;
}
