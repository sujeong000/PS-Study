#include <iostream>
#include <vector>

using namespace std;

int N;
string S;

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t = 1;
    while (true) {
        cin >> N;
        if (N == 0) break;
        
        cin >> S;
        vector<int> pi = getPartialMatch(S);
        
        cout << "Test case #" << t++ << "\n";
        for (int i=0; i<N; i++) {
            int suffix = pi[i];
            int prefix = (i+1) - pi[i];
            int n = suffix/prefix;
            
            if (suffix % prefix == 0 && n > 0) {
                cout << i+1 << " " << n+1 << "\n";
            }
        }
        cout << "\n";
    }

    return 0;
}
