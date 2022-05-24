#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

string S;
ll K;

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

ll minLength() {
    vector<int> pi = getPartialMatch(S);
    ll len = S.size();
    
    return len + (K-1)*(len - pi[len-1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> S >> K;
    cout << minLength();

    return 0;
}
