#include <iostream>
#include <vector>

using namespace std;

string A, B;

vector<int> getPartialMatch(const string& N) {
    int m = N.size();
    vector<int> pi(m, 0);
    
    int begin = 1, matched = 0;
    while (begin+matched < m) {
        if (N[begin+matched] == N[matched]) {
            matched++;
            pi[begin+matched-1] = matched;
        }
        else {
            if (matched == 0) begin++;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    
    return pi;
}

int KMP(const string& H, const string& N) {
    int n = H.size(), m = N.size();
    vector<int> pi = getPartialMatch(N);
    int ret = 0;
    
    int begin = 0, matched = 0;
    while (begin <= n-m) {
        if (matched < m && H[begin+matched] == N[matched]) {
            matched++;
            if (matched == m) ret++;
        }
        else {
            if (matched == 0) begin++;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> A >> B;
    
    int ans = KMP(B+B, A);
    if (A == B) ans--;
    
    cout << ans;

    return 0;
}
