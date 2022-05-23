#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

const int MAX = 1000001;

string T, P;

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

vector<int> KMP(string& H, string& N) {
    int n = H.size(), m = N.size();
    vector<int> pi = getPartialMatch(N);
    vector<int> ret;
    
    int begin = 0, matched = 0;
    while (begin <= n-m) {
        if (matched < m && H[begin+matched] == N[matched]) {
            matched++;
            if (matched == m) ret.push_back(begin);
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
    
    getline(cin, T);
    getline(cin, P);
    
    vector<int> ans = KMP(T, P);
    
    cout << ans.size() << "\n";
    for (auto i : ans) cout << i+1 << "\n";

    return 0;
}
