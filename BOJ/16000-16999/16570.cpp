#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;

int N;
int A[MAX];

vector<int> getPartialMatch() {
    int m = N;
    vector<int> pi(m, 0);
    
    int begin = 1, matched = 0;
    while (begin+matched < m) {
        if (A[begin+matched] == A[matched]) {
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

int findMaxK(const vector<int>& pi) {
    int ret = 0;
    
    for (int i=0; i<N; i++) {
        ret = max(ret, pi[i]);
    }
    
    return ret;
}

int countMaxK(const vector<int>& pi, int maxK) {
    int ret = 0;
    
    for (int i=0; i<N; i++) {
        if (pi[i] == maxK) ret++;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i=0; i<N; i++) cin >> A[N-1-i];
    
    vector<int> pi = getPartialMatch();
    int maxK = findMaxK(pi);
    
    if (maxK == 0) cout << -1;
    else cout << maxK << " " << countMaxK(pi, maxK);

    return 0;
}
