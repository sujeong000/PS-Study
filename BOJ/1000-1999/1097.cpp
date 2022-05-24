#include <iostream>
#include <vector>

using namespace std;

int N, K;
string words[8];

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

bool isMagicWord(const string& word) {
    return KMP(word+word, word)-1 == K;
}

int DFS(string s, int mask) {
    if (mask == ((1 << N) -1)) {
        return isMagicWord(s) ? 1 : 0;
    }
    
    int ret = 0;
    
    for (int i=0; i<N; i++) {
        if ((mask & (1 << i)) != 0) continue;
        ret += DFS(s+words[i], mask|(1<<i));
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i=0; i<N; i++) cin >> words[i];
    cin >> K;
    
    cout << DFS("", 0);

    return 0;
}
